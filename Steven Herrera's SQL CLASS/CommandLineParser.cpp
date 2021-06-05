#include "CommandLineParser.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer\STokenizer.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer\token.h"
#include "C:/Users/Steven_Dev/Desktop/CS_Stuff/includes/\table.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Map-Class\MapClass\MapClass\Map.h"
#include <iostream>

using namespace std;
Parser::Parser() {
	build_keyword_list();
	make_table(_adjancencyMatrix);
	_flag = false;

}

Parser::Parser(char* s) : _st(s) {
	_token = Token();
	//builds all the keywords we have for the table
	build_keyword_list();
	make_table(_adjancencyMatrix);
	set_string(s);
}

void Parser::build_keyword_list() {
	_keyWords.insert("select", select);
	_keyWords.insert("from", from);
	_keyWords.insert("where", where);
	_keyWords.insert("other", other);
	_keyWords.insert("<", Operator);
	_keyWords.insert("=", Operator);
	_keyWords.insert(">", Operator);
	_keyWords.insert(">=", Operator);
	_keyWords.insert("<=", Operator);
	_keyWords.insert("star", star);
	_keyWords.insert("or", Or);
	_keyWords.insert("and", And);
	_keyWords.insert("insert", insert);
	_keyWords.insert("into", into);
	_keyWords.insert("create", create);
	_keyWords.insert("make", make);
	_keyWords.insert(",", comma);
	_keyWords.insert("drop", drop);
	_keyWords.insert("table", table);
	_keyWords.insert("delete", Delete);
	_keyWords.insert("values", values);
	_keyWords.insert("fields", fields);
	_keyWords.insert("(", leftPara);
	_keyWords.insert(")", rightPara);
}

void Parser::make_table(int _adjancencyMatrix[][MAX_COLUMN]) {
	//marks all cells as -1 
	mark_cells(_adjancencyMatrix, 0, MAX_ROW, 0, MAX_COLUMN, -1);

	//rows reserved as passing states
	mark_cells(_adjancencyMatrix, 23, 0, 1);
	mark_cells(_adjancencyMatrix, 6, 0, 1);
	mark_cells(_adjancencyMatrix, 16, 0, 1);
	mark_cells(_adjancencyMatrix, 10, 0, 1);
	mark_cells(_adjancencyMatrix, 33, 0, 1);
	mark_cells(_adjancencyMatrix, 42, 0, 1);

	//takes care of the insert into for the table
	mark_cells(_adjancencyMatrix, 0, insert, 20);
	mark_cells(_adjancencyMatrix, 20, into, 21);
	mark_cells(_adjancencyMatrix, 21, other, 22);
	mark_cells(_adjancencyMatrix, 22, other, 23);
	mark_cells(_adjancencyMatrix, 22, values, 19);
	mark_cells(_adjancencyMatrix, 19, other, 23);
	mark_cells(_adjancencyMatrix, 23, comma, 24);
	mark_cells(_adjancencyMatrix, 24, other, 23);

	//takes care of the select <fields> from <table name> <conditions>
	mark_cells(_adjancencyMatrix, 0, select, 1);
	mark_cells(_adjancencyMatrix, 1, star, 5);
	mark_cells(_adjancencyMatrix, 1, other, 2);
	mark_cells(_adjancencyMatrix, 2, from, 3);
	mark_cells(_adjancencyMatrix, 2, comma, 4);
	mark_cells(_adjancencyMatrix, 3, other, 6);
	mark_cells(_adjancencyMatrix, 4, other, 2);
	mark_cells(_adjancencyMatrix, 6, where, 7);
	mark_cells(_adjancencyMatrix, 7, other, 8);
	mark_cells(_adjancencyMatrix, 8, Operator, 9);
	mark_cells(_adjancencyMatrix, 9, other, 10);
	mark_cells(_adjancencyMatrix, 10, Or, 11);
	mark_cells(_adjancencyMatrix, 10, And, 11);
	mark_cells(_adjancencyMatrix, 11, other, 8);
	mark_cells(_adjancencyMatrix, 7, leftPara, 12);
	mark_cells(_adjancencyMatrix, 11, leftPara, 12);
	mark_cells(_adjancencyMatrix, 12, leftPara, 12);
	mark_cells(_adjancencyMatrix, 12, other, 13);
	mark_cells(_adjancencyMatrix, 13, Operator, 14);
	mark_cells(_adjancencyMatrix, 14, other, 15);
	mark_cells(_adjancencyMatrix, 15, Or, 17);
	mark_cells(_adjancencyMatrix, 15, And, 17);
	mark_cells(_adjancencyMatrix, 15, rightPara, 16);
	mark_cells(_adjancencyMatrix, 16, rightPara, 16);
	mark_cells(_adjancencyMatrix, 16, And, 11);
	mark_cells(_adjancencyMatrix, 16, Or, 11);
	mark_cells(_adjancencyMatrix, 17, other, 13);

	//takes care of the create/make <table name> fields <list of fields>
	mark_cells(_adjancencyMatrix, 0, create, 30);
	mark_cells(_adjancencyMatrix, 0, make, 30);
	mark_cells(_adjancencyMatrix, 30, table, 31);
	mark_cells(_adjancencyMatrix, 31, other, 32);
	mark_cells(_adjancencyMatrix, 29, other, 33);
	mark_cells(_adjancencyMatrix, 33, comma, 34);
	mark_cells(_adjancencyMatrix, 32, fields, 29);
	mark_cells(_adjancencyMatrix, 34, other, 33);

	//this takes care of dropping tables
	mark_cells(_adjancencyMatrix, 0, drop, 40);
	mark_cells(_adjancencyMatrix, 40, table, 41);
	mark_cells(_adjancencyMatrix, 41, other, 42);

	//takes care of the deletion of tables
	mark_cells(_adjancencyMatrix, 0, Delete, 50);
	mark_cells(_adjancencyMatrix, 50, from, 51);
	mark_cells(_adjancencyMatrix, 51, other, 52);
	mark_cells(_adjancencyMatrix, 52, where, 7);
}

MMap<string,string> Parser::parse_tree() {
	return _parseTree;
}

bool Parser::get_parse_tree() {
	string item;
	int state = 0;
	for (int i = 0; i < input_q.size(); i++) {
		item = input_q[i];
		if (state == -1) {
			break;
		}
		if (_keyWords.contains(item)) {
			state = _adjancencyMatrix[state][_keyWords[item]];
		} else {
			state = _adjancencyMatrix[state][other];
		}
		
		//checks the state and based on where we end we insert into the proper parse tree table
		switch (state) {
		case select:
			_parseTree.insert("command", item);
			break;
		case from:
			_parseTree.insert("fields", item);
			break;
		case 6:
			_parseTree.insert("table", item);
			break;
		case 7:
			_parseTree.insert("where", "yes");
			break;
		case 8:
			_parseTree.insert("conditions", item);
			break;
		case 9:
			_parseTree.insert("conditions", item);
			break;
		case 10:
			_parseTree.insert("conditions", item);
			break;
		case 11:
			_parseTree.insert("conditions", item);
			break;
		case 12:
			_parseTree.insert("conditions", item);
			break;
		case 13:
			_parseTree.insert("conditions", item);
			break;
		case 14:
			_parseTree.insert("conditions", item);
			break;
		case 15:
			_parseTree.insert("conditions", item);
			break;
		case 16:
			_parseTree.insert("conditions", item);
			break;
		case 17:
			_parseTree.insert("conditions", item);
			break;
		case 20:
			_parseTree.insert("command", item);
			break;
		case 22:
			_parseTree.insert("table", item);
			break;
		case 23:
			_parseTree.insert("fields", item);
			break;
		case 30:
			_parseTree.insert("command", item);
			break;
		case 32:
			_parseTree.insert("table", item);
			break;
		case 33:
			_parseTree.insert("fields", item);
			break;
		case 40:
			_parseTree.insert("command", item);
			break;
		case 42:
			_parseTree.insert("table", item);
			break;
		case 50:
			_parseTree.insert("command", item);
			break;
		case 52:
			_parseTree.insert("table", item);
			break;
		case 53:
			_parseTree.insert("where", "yes");
			break;
		case 54:
			_parseTree.insert("conditions", item);
			break;
		case 55:
			_parseTree.insert("conditions", item);
			break;
		case 56:
			_parseTree.insert("conditions", item);
			break;
		case 57:
			_parseTree.insert("conditions", item);
			break;
		default:
			break;
		}
	}
	if (state != -1 && _adjancencyMatrix[state][0] == 1) {
		return true;
	} else {
		_parseTree.clear();
		return false;
	}
}

void Parser::set_string(char* s) {
	input_q.clear();
	_st.set_string(s);
	_parseTree.clear();
	_token = Token();
	_st >> _token;
	while (_st.more()) {
		//checks that the thing we are inserting is not a space or " or other 
		if (_token.type() != Space && _token.token_str() != "\"" && _token.type() != -1) {
			string temp = _token.token_str();
			if (temp[0] == '\"') {
				temp.erase(0, 1);
				temp.erase(temp.size()-1, 1);
				input_q.push_back(temp);
			//this checks if our token comes back as a double parenthesis and splits it up to insert it into the conditions vector
			} else if (temp.size() == 2 && temp == "((" || temp == "))") {
				temp = temp[0];
				input_q.push_back(temp);
				input_q.push_back(temp);
			} else {
				input_q.push_back(_token.token_str());
			}
			
		}
		_token = Token();
		_st >> _token;
	}
	_flag = get_parse_tree();

}