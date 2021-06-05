#ifndef CommandLineParser_H_
#define CommandLineParser_H_

#define MAX_COLUMN 21
#define MAX_ROW 60

#include "C:/Users/Steven_Dev/Desktop/CS_Stuff/includes/\table.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer\STokenizer.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\stringTokenizer\StringTokenizer\token.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Map-Class\MapClass\MapClass\Map.h"
#include "C:\Users\Steven_dev\Desktop\CS_Stuff\Map-Class\MapClass\MapClass\MultiMap.h"
#include <iostream>

using namespace std;

enum Keywords {
	select = 1, from, where, other, Operator,
	star, Or, And, insert, into, create, make, comma,
	drop, table, Delete, values, fields ,leftPara, rightPara
};

class Parser{
private:
	int _adjancencyMatrix[MAX_ROW][MAX_COLUMN];
	Token _token;
	STokenizer _st;
	Map<string,int> _keyWords;
	bool _flag;
	Vector<string> input_q;
	MMap<string, string> _parseTree;
	//creates the entire adjacency matrix which is what decides what is a valid input
	void make_table(int _adjancencyMatrix[][MAX_COLUMN]);
	void build_keyword_list();
public:
	Parser();
	Parser(char* s);
	MMap<string,string> parse_tree();
	bool get_parse_tree();
	void set_string(char* s);
};

#endif // !CommandLineParser_H_
