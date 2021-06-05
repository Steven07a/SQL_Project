#ifndef TABLE_H_
#define TABLE_H_

#include <iostream>
#include <string>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\vector\vector\vector\Vector.h"
#include "Record.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Map-Class\MapClass\MapClass\Map.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Map-Class\MapClass\MapClass\MultiMap.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\shunting_yard\shunting_yard\shunting_yard\SY.h"

using namespace std;

class Table {
private:
	string _name;
	string _fileName;
	Vector<string> _field_list;
	Map<string,int> field_map;
	Vector<MMap<string, long> > indices;
	Record r;
	fstream f;
	int data_count;
	static int serial_num;

	//reindexes indices only used when we open a previously made table
	void reindex(Vector<string>field_list,int position);
	// this is where we take care of the RPN notation 
	Vector<long> getPositions(Vector<string> conditions);
	//returns a vector of positions for one condition ex: age < 30
	Vector<long> getPosition(Vector<string> conditions);
	void print_table();
	//checks if the current string is an operator (<,>,>=,= etc)
	bool is_operator(string item);

public:
	//constructors for Table
	Table(string n, Vector<string> fl);
	Table(const Table& RHS);
	//constructor for Table will open a prexisting table and reindex it
	Table(string n);
	Table();
	void insert_into(Vector<string> field_list);
	//opens the table and selects items based on the fields given and conditions given	
	Table select(Vector<string>fields, Vector<string>conditions = Vector<string>());
	//sets an item to be removed from the table by setting the deleted field in the file to true
	void remove(Vector<string>conditions);
	Table select_all();

	//copy constructor for Table
	Table& operator =(const Table& RHS) {
		_name = RHS._name;
		_fileName = (RHS._name + (to_string(RHS.serial_num)) + ".bin");
		_field_list = (RHS._field_list);
		field_map = RHS.field_map;
		indices = RHS.indices;
		f = fstream();
		r = RHS.r;
		data_count = RHS.data_count;
		serial_num = RHS.serial_num;
		return *this;
	}

	friend ostream& operator<<(ostream& outs, Table& print_me) {
		print_me.print_table();
		return outs;
	}

};

int Table::serial_num = 1000;

void Table::print_table() {
	open_fileRW(f, _fileName.c_str());
	Vector<Vector<string> > temp;
	int recordsCount = 0;
	for (int i = 0; i < data_count + 1; i++) {
		r.read(f, i);
		temp.push_back(r.get_record());
		if (temp[i][0] == "yes") {
			recordsCount--;
		}
	}
	f.close();
	recordsCount += (temp.size() - 1);
	cout << "Table name " << _name << ", records: " << recordsCount << endl;

	if (false) {
		//debug print for table
		for (int i = 0; i < temp.size(); i++) {
			cout << temp[i] << endl;
		}
	} else {
		//proper print function for table
		cout  << right << "record";
		for (int i = 1; i < _field_list.size(); i++) {
			cout << setw(15) << right << temp[0][i];
		}
		cout << endl;
		recordsCount = 0;
		for (int i = 1; i < data_count + 1; i++) {
			if (temp[i][0] == "no") {
				cout  << setw(6) << right << recordsCount++;
				temp[i].print_from_index(1);
				cout << endl;
			}
		}
	}
}

Table::Table() {
	_name = "";
	_fileName = "";
	_field_list;
	field_map;
	indices;
	r;
	f;
	data_count = 0;
	serial_num;
}

Table::Table(string n) {
	_fileName = n + "1000.bin";
	_name = n;
	data_count = 0;
	Vector<Vector<string> > records;
	Vector<string> tempFieldList;
	int tempFieldListSize = 0;

	if (file_exists(_fileName.c_str())) {
		open_fileRW(f, _fileName.c_str());
		int index = 0;
		for (int i = 0; !f.eof(); i++) {
			r.read(f, index);
			//this gets the first item from the file which is our list of fields
			if (index == 0) {
				tempFieldList = r.get_record();
				for (int i = 0; i < tempFieldList.size(); i++) {
					if (tempFieldList[i] != "") {
						_field_list.push_back(tempFieldList[i]);
						field_map.insert(_field_list[i], i);
						MMap<string, long> temp;
						tempFieldListSize++;
						indices.push_back(temp);
					} else {
						break;
					}
				}
			} else {
				if (f.peek() != f.eof()) {
					records.push_back(r.get_record());
				}
				data_count++;
				this->reindex(records[index-1], index);
			}

			
			index++;
		}
		f.close();
	}
}

Table::Table(const Table& RHS) {
	*this = RHS;
}

Table::Table(string n, Vector<string> fl) : _fileName(n+to_string(serial_num)+".bin") , indices(fl.size()+1) {
	_name = n;
	data_count = 0;
	MMap<string, long>temp;
	Vector<string> fl1;
	if (fl[0] != "deleted") {
		fl1.push_back("deleted");
		for (int i = 0; i < fl.size(); i++) {
			fl1.push_back(fl[i]);
		}
	} else {
		fl1 = fl;
	}
	
	for (int i = 0; i < fl1.size(); i++) {
		_field_list.push_back(fl1[i]);
		field_map.insert(fl1[i],i);
		indices.push_back(temp);
	}
	open_fileW(f, _fileName.c_str());
	Record r(_field_list);
	r.write(f);
	f.close();
	
}

void Table::insert_into(Vector<string> field_list) {
	long pos = 0;
	Vector<string> fl;
	//checks if the field list has a no or yes inside of the first field if not we need to add it
	if (field_list[0] == "no" || field_list[0] == "yes") {
		fl = field_list;
	} else {
		fl.push_back("no");
		for (int i = 0; i < field_list.size(); i++) {
			if (field_list[i] == "") {
				break;
			} else {
				fl.push_back(field_list[i]);
			}
		}
	}

	//opens up the file and inserts the fields into that file 
	//our original file is kep due to us giving this file a different serial number
	open_fileRW(f, _fileName.c_str());
	Record t(fl);
	pos = t.write(f);
	f.close();
	data_count++;
	MMap<string, long>temp;
	temp.insert(fl[0], pos);
	for (int i = 0; i < fl.size(); i++) {
		if (fl[i] == "") {
			break;
		}
		indices[field_map[_field_list[i]]].insert(fl[i], pos);
	}


}

Table Table::select_all() {
	//opens the file and gets all the informaiton from the file
	//then returns everything
	open_fileRW(f, _fileName.c_str());
	Vector<Vector<string> > temp;
	for (int i = 0; i < data_count+1; i++) {
		r.read(f,i);
		temp.push_back(r.get_record());
	}
	f.close();

	serial_num++;
	Table tempTable(_name, _field_list);
	for (int i = 1; i < temp.size(); i++) {
		tempTable.insert_into(temp[i]);
	}

	return tempTable;
	
}

Table Table::select(Vector<string>fields, Vector<string>conditions) {
	Vector<Vector<string> > output;
	Vector<long> pos;

	if (conditions.size() > 0) {
		pos = getPositions(conditions);
		//opens the file up and reads the data from the positions found
		open_fileRW(f, _fileName.c_str());
		for (int i = 0; i < pos.size(); i++) {
			r.read(f, pos[i]);
			output.push_back(r.get_record());
		}
		f.close();
	} else {
		//reads from the file all positions except the first since that is reserved for the fields
		open_fileRW(f, _fileName.c_str());
		for (int i = 1; i < data_count + 1; i++) {
			r.read(f, i);
			output.push_back(r.get_record());
		}
		f.close();
	}
	

	//creates a new vector and only pushes back the columns we need according to the fields given
	Vector<Vector<string> > output1(output.size());
	if (fields[0] == "*") {
		Vector<string> tempFields = _field_list;
		for (int i = 0; i < output.size(); i++) {
			for (int j = 0; j < _field_list.size(); j++) {
				output1[i].push_back((output[i][field_map[_field_list[j]]]));
			}
		}
		//creates a new table with a different serial number using this information and returns it
		serial_num++;
		Table temp(_name, tempFields);
		for (int i = 0; i < output.size(); i++) {
			temp.insert_into(output1[i]);
		}
		return temp;
	} else {
		for (int i = 0; i < output.size(); i++) {
			output1[i].push_back(output[i][0]);
			for (int j = 0; j < fields.size(); j++) {
				output1[i].push_back((output[i][field_map[fields[j]]]));
			}
		}
		//creates a new table with a different serial number using this information and returns it
		serial_num++;
		Table temp(_name, fields);
		for (int i = 0; i < output.size(); i++) {
			temp.insert_into(output1[i]);
		}
		return temp;
	}

}

void Table::reindex(Vector<string> field_list,int position) {
	for (int i = 0; i < field_list.size(); i++) {
		//cout << "field_list: \n" << field_list[i] << "\n";
		if (field_list[i] == "") {
			break;
		}
		indices[field_map[_field_list[i]]].insert(field_list[i], position);
	}
}

Vector<long> Table::getPositions(Vector<string> conditions){
	Vector<long> pos;
	SY sy(conditions);
	Vector<string> tempCommand;
	Queue<string> shunted_string_q;
	Queue<string> commands;
	Stack<Vector<long> > vec_post_commands;
	shunted_string_q = sy.getShunted();

	while (!shunted_string_q.empty()) {
		string temp = shunted_string_q.pop();
		if (!is_operator(temp)) {
			commands.push(temp);
		} else if (temp == "and") {
			Vector<long> temp1 = vec_post_commands.pop();
			Vector<long> temp2 = temp1.getIntersection(vec_post_commands.pop());
			vec_post_commands.push(temp2);
		} else if (temp == "or") {
			Vector<long> temp1 = vec_post_commands.pop();
			Vector<long> temp2 = temp1.vecmerge(vec_post_commands.pop());
			vec_post_commands.push(temp2);
		} else {
			tempCommand.push_back(commands.pop());
			tempCommand.push_back(temp);
			tempCommand.push_back(commands.pop());
			vec_post_commands.push(getPosition(tempCommand));
			tempCommand.clear();
		}

	}
	pos = vec_post_commands.pop();

	//Do one final check if this is true that then means nothing was found 
	//since we know the 0th position is reserverd for the fields. So we clear it 
	//and return an empty vector
	if (pos.size() == 1 && pos[0] == 0) {
		pos.clear();
	}

	return pos;
}

Vector<long> Table::getPosition(Vector<string> conditions) {
	Vector<long> pos;
	if (conditions.size() == 0) {
		MMap<string, long>::Iterator end = indices[field_map[_field_list[0]]].end();
		MMap<string, long>::Iterator begin = indices[field_map[_field_list[0]]].begin();
		for (MMap<string, long>::Iterator it = begin; it != end; it++) {
			auto temp = *it;
			pos.push_back(temp.value_list);
		}
	} else {
		if (conditions[1] == "=") {
			pos = indices[field_map[conditions[0]]][conditions[2]];

		} else if (conditions[1] == "<") {
			MMap<string, long>::Iterator up = indices[field_map[conditions[0]]].lower_bound(conditions[2]);
			MMap<string, long>::Iterator begin = indices[field_map[conditions[0]]].begin();

			if (up.is_null()) {
				up = indices[field_map[conditions[0]]].end();
				for (MMap<string, long>::Iterator it = begin; it != up; it++) {
					auto temp = *it;
					pos.push_back(temp.value_list);
				}
			} else {
				for (MMap<string, long>::Iterator it = begin; *it < *up; it++) {
					auto temp = *it;
					pos.push_back(temp.value_list);
				}
			}
			

		} else if (conditions[1] == "<=") {
			MMap<string, long>::Iterator up = indices[field_map[conditions[0]]].upper_bound(conditions[2]);
			MMap<string, long>::Iterator begin = indices[field_map[conditions[0]]].begin();
			if (up.is_null()) {
				up = indices[field_map[conditions[0]]].end();
				for (MMap<string, long>::Iterator it = begin; it != up; it++) {
					auto temp = *it;
					pos.push_back(temp.value_list);
				}
			} else {
				for (MMap<string, long>::Iterator it = begin; *it < *up; it++) {
					auto temp = *it;
					pos.push_back(temp.value_list);
				}
			}
			

		} else if (conditions[1] == ">") {
			MMap<string, long>::Iterator begin = indices[field_map[conditions[0]]].upper_bound(conditions[2]);
			MMap<string, long>::Iterator end = indices[field_map[conditions[0]]].end();
			if (begin.is_null()) {
				begin = indices[field_map[conditions[0]]].end();
				for (MMap<string, long>::Iterator it = begin; it != end; it++) {
					auto temp = *it;
					pos.push_back(temp.value_list);
				}
			} else {
				for (MMap<string, long>::Iterator it = begin; it != end; it++) {
					auto temp = *it;
					pos.push_back(temp.value_list);
				}
			}

		} else if (conditions[1] == ">=") {
			MMap<string, long>::Iterator begin = indices[field_map[conditions[0]]].lower_bound(conditions[2]);
			MMap<string, long>::Iterator end = indices[field_map[conditions[0]]].end();
			if (begin.is_null()) {
				begin = indices[field_map[conditions[0]]].end();
			} else {
				for (MMap<string, long>::Iterator it = begin; it != end; it++) {
					auto temp = *it;
					pos.push_back(temp.value_list);
				}
			}
		}
	}

	//we remove any 0 as this index is only used to store the fields the table has
	if (pos.contains(0)) {
		pos.remove(0);
	}
	return pos;
}

void Table::remove(Vector<string>conditions) {
	Vector<long> pos;
	pos = getPositions(conditions);
	open_fileRW(f, _fileName.c_str());
	Vector<Vector<string> > temp;
	for (int i = 0; i < pos.size(); i++) {
		r.read(f, pos[i]);
		temp.push_back(r.get_record());
		//we know the first position is where we have the deleted flag at so we overwrite at that position
		temp[i][0] = "yes";
		Record tempRecord(temp[i]);
		//opens the file then overwrites at the position of the thing we are deleting
		tempRecord.write(f, pos[i]);
	}
	f.close();
}

bool Table::is_operator(string item) {
	if (item == ">") {
		return true;
	} else if (item == "<") {
		return true;
	} else if (item == "<=") {
		return true;
	} else if (item == ">=") {
		return true;
	} else if (item == "=") {
		return true;
	} else if (item == "and") {
		return true;
	} else if (item == "or") {
		return true;
	}else {
		return false;
	}
}

#endif // !TABLE_H_