#ifndef SQL_H_
#define SQL_H_

#include <iostream>
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\CommandLineParser\CommandLineParser\CommandLineParser\CommandLineParser.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\TableClass\TableClass\TableClass\Record.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\TableClass\TableClass\TableClass\Table.h"

using namespace std;

class SQL
{
public:
	SQL();
	//takes in the initial input and figures out if its running from a file or from user input
	void run();
	//runs the code form a file 
	void batchRun(string fileName);
	//runs the code based on user input
	void userInputRun(string in);
private:
	void save_files();
	Parser p;
	Map<string, Table> table;
	Vector<string> fileNames;
};

SQL::SQL() 
{
	ifstream f;
	f.open("saveFileNames.txt", fstream::in);
	string temp1;
	if (f.is_open()) {
		int num = 0;
		while (getline(f,temp1)) {
			fileNames.push_back((temp1));
			num++;
		}
	}
	f.close();
	for (int i = 0; i < fileNames.size(); i++) {
		table.insert(fileNames[i], Table(fileNames[i]));
	}
	p;
}

void SQL::save_files() {
	table.clear();
	ofstream f("saveFileNames.txt");
	if (f.is_open()) {
		f.clear();
		for (int i = 0; i < fileNames.size(); i++) {
			f << fileNames[i] << endl;
		}
	}
	f.close();
}

void SQL::run() {
	string input = "";
	cout << "SQL> ";
	getline(cin, input);
	if (input.compare(0, 5, "batch") == 0) {
		input.erase(0, 6);
		batchRun(input);
	} else {
		userInputRun(input);
	}
}

void SQL::batchRun(string file_name) {
	char charInput[200];
	bool debug = false;
	
	int commandCount = 0;
	ifstream f;
	f.open(file_name);
	if (f.is_open()) {
		while (!f.eof()) {
			f.getline(charInput, 200);
			if (charInput[0] == '/' || charInput[0] == '\\' || charInput[0] == '\0') {
				cout << charInput << endl;
				charInput[0] = '\0';
			} else {
				MMap <string, string> ptree;
				p.set_string(charInput);
				charInput[0] = '\0';
				ptree = p.parse_tree();
				if (!ptree.empty()) {
					if (debug) {
						cout << "\n\n\n\n";
						ptree.print_table();
						cout << "\n\n\n\n";
					}
					if (ptree.contains("where")) {
						if (fileNames.contains(ptree["table"][0])) {
							if (ptree["command"][0] == "select") {
								cout << "\n[" << commandCount++ << "] " << ptree["command"][0]
									<< " " << ptree["fields"] << "from " << ptree["table"][0]
									<< " where " << ptree["conditions"] << endl;
								Table temp = table[ptree["table"][0]].select(
									ptree["fields"],
									ptree["conditions"]);
								cout << temp;
								cout << "\n";
							} else if (ptree["command"][0] == "delete") {
								if (table.contains(ptree["table"][0])) {
									table[ptree["table"][0]].remove(ptree["conditions"]);
								
									cout << "\n[" << commandCount++ << "] " << ptree["command"][0]
										<< " " << ptree["fields"] << "from " << ptree["table"][0]
										<< " where " << ptree["conditions"] << endl;
								}
							}
						}
					} else {
						if (ptree["command"][0] == "create") {
							table.insert(ptree["table"][0], Table(ptree["table"][0], ptree["fields"]));
							if (!fileNames.contains(ptree["table"][0])) {
								fileNames.push_back(ptree["table"]);
							}

							cout << "[" << commandCount++ << "] create table "
								<< ptree["table"][0] << " cols: " << ptree["fields"]
								<< "\nTable " << ptree["table"][0] << " created. cols: "
								<< ptree["fields"] << endl;

						} else if (ptree["command"][0] == "make") {
							table.insert(ptree["table"][0], Table(ptree["table"][0], ptree["fields"]));
							if (!fileNames.contains(ptree["table"][0])) {
								fileNames.push_back(ptree["table"]);
							}

							cout << "[" << commandCount++ << "] make table "
								<< ptree["table"][0] << " cols: " << ptree["fields"]
								<< "\nTable " << ptree["table"][0] << " created. cols: "
								<< ptree["fields"] << endl;

						} else if (ptree["command"][0] == "insert") {
							if (fileNames.contains(ptree["table"][0])) {
								table[ptree["table"][0]].insert_into(ptree["fields"]);
								cout << "[" << commandCount++ << "] insert into " << ptree["table"][0]
									<< " values: " << ptree["fields"] << "\n";

							}
						} else if (ptree["command"][0] == "select") {
							if (fileNames.contains(ptree["table"][0])) {
								if (ptree["fields"][0] == "*") {
									cout << "\n[" << commandCount++ << "] " << ptree["command"]
										<< " " << ptree["fields"][0] << " from " << ptree["table"] << endl;
									Table temp = table[ptree["table"][0]].select_all();
									cout << temp;
									cout << endl;
								} else {
									cout << "\n[" << commandCount++ << "] " << ptree["command"]
										<< " " << ptree["fields"][0] << " from " << ptree["table"] << endl;
									Table temp = table[ptree["table"][0]].select(ptree["fields"]);
									cout << temp << endl;
								}
							}
						} else if (ptree["command"][0] == "drop") {
							if (fileNames.contains(ptree["table"][0])) {
								if (table.contains(ptree["table"][0])) {
									table.erase(ptree["table"][0]);
									fileNames.remove(ptree["table"][0]);
								
									cout << "\n[" << commandCount++ << "] " << ptree["command"][0]
										<< "Table: " << ptree["table"][0]
										<< endl;
								}
							}
						}
					}
				}
				cout << "SQL: DONE.\n\n";
			}
		}
		save_files();
	}
}

void SQL::userInputRun(string in) {
	string input;
	bool debug = false;
	
	while (true) {
		
		if (in.empty()) {
			cout << "SQL> ";
			getline(cin, input);
		} else {
			input = in;
			in.clear();
		}


		if (input == "exit") {
			break;
		} else {
			MMap <string, string> ptree;
			char charInput[100];
			strcpy(charInput, input.c_str());

			p.set_string(charInput);
			input.clear();
			strcpy(charInput, input.c_str());

			ptree = p.parse_tree();
			if (debug) {
				cout << "\n\n\n\n";
				ptree.print_table();
				cout << "\n\n\n\n";
			}
			//if the ptree is empty that means we got invalid input from the user
			if (!ptree.empty()) {
				if (ptree.contains("where")) {
					if (ptree["command"][0] == "select") {
						cout << "\n";
						Table temp = table[ptree["table"][0]].select(
							ptree["fields"],
							ptree["conditions"]);
						cout << temp;
						cout << "\n";
					} else if (ptree["command"][0] == "delete") {
						if (table.contains(ptree["table"][0])) {
							table[ptree["table"][0]].remove(ptree["conditions"]);
						}
					}
				} else {
					if (ptree["command"][0] == "create" || ptree["command"][0] == "make") {
						if (!fileNames.contains(ptree["table"][0])) {
							table.insert(ptree["table"][0], Table(ptree["table"][0], ptree["fields"]));
							fileNames.push_back(ptree["table"]);
						} else {
							cout << "Table " << ptree["table"][0] << " already exist.\n";
						}
					} else if (ptree["command"][0] == "insert") {
						table[ptree["table"][0]].insert_into(ptree["fields"]);
					} else if (ptree["command"][0] == "select") {
						if (ptree["fields"][0] == "*") {
							if (table.contains(ptree["table"][0])) {
								cout << endl;
								Table temp = table[ptree["table"][0]].select_all();
								cout << temp;
								cout << endl;
							} else {
								cout << "\nNo such table exist\n";
							}

						} else {
							cout << endl;
							Table temp = table[ptree["table"][0]].select(ptree["fields"]);
							cout << temp << endl;
						}
					} else if (ptree["command"][0] == "drop") {
						if (table.contains(ptree["table"][0])) {
							table.erase(ptree["table"][0]);
							fileNames.remove(ptree["table"][0]);
						} else {
							cout << "\nTable " << ptree["table"][0] << " does not exist.\n";
						}
					}
				}
			} else {
				cout << "Invalid input.\n";
			}
			

		}
	}
	save_files();
}

#endif // !SQL_H_