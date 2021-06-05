#include "STokenizer.h"
#include "C:/Users/Steven_Dev/Desktop/CS_Stuff/includes/table.h"

int STokenizer::_table[MAX_ROWS_ST][MAX_COLUMNS_ST];


STokenizer::STokenizer() {
	set_string(0);
	_pos = 0;
	make_table(_table);
}

STokenizer::STokenizer(char str[]) {
	_stringSize = strlen(str);
	_pos = 0;
	set_string(str);
	make_table(_table);
}

bool STokenizer::done() {
	return (_pos <= _stringSize);
}

bool STokenizer::more() {
	return (_pos <= _stringSize);
}

void STokenizer::set_string(char str[]) {
	char* strP = str;
	if (strP != NULL) {
		_stringSize = strlen(str);
	} else {
		_stringSize = 0;
	}
	_pos = 0;
	for (int i = 0; i < MAX_BUFFER; i++) {
		_buffer[i] = 0;
	}
	if (strP != NULL) {
		for (int i = 0; str[i] != NULL; i++) {
			_buffer[i] = str[i];
		}
	}
	
}

void STokenizer::make_table(int _table[][MAX_COLUMNS_ST]) {
	//sets default value to -1
	mark_cells(_table, 0, MAX_ROWS_ST, 0, MAX_COLUMNS_ST, -1);

	//row 0 is reserved for the default state it will give us the proper
	//state to go to
	mark_cells(_table, 0, 0, '0', '9', Number);
	mark_cells(_table, 0, 0, ' ', ' ', Space);
	mark_cells(_table, 0, 0, 'A', 'Z', Word);
	mark_cells(_table, 0, 0, 'a', 'z', Word);
	mark_cells(_table, 0, 0, "<>*&^%$#@_+-=~", Symbol);
	mark_cells(_table, 0, 0, "\"';:{}[](),.?/!", Puncuation);

	//row 1-3 reserved for number 1 pass, 2 neutral, 3 fail
	mark_cells(_table, 1, 3, '0', '9', Number);
	mark_cells(_table, 1, 2, '.', '.', Number + 1);
	mark_cells(_table, 1, 1, 0, 0, 1);
	mark_cells(_table, 2, 2, 0, 0, 0);

	//row 7-9 reserved for words 7 pass, 8 neutral, 9 fail
	mark_cells(_table, 7, 9, 'A', 'Z', Word);
	mark_cells(_table, 7, 9, 'a', 'z', Word);
	mark_cells(_table, 7, 9, '0', '9', Word);
	mark_cells(_table, 7, 9, '.', '.', Word);
	mark_cells(_table, 7, 8, '\'','\'' , Word + 1);
	mark_cells(_table, 7, 7, '\"','\"' , MAX_ROWS_ST-1);
	mark_cells(_table, 7, 7, '.', '.', MAX_ROWS_ST - 1);
	mark_cells(_table, 8, 8, ' ',' ' , Word + 1);
	mark_cells(_table, 7, 7, 0, 0, 1);
	mark_cells(_table, 8, 8, 0, 0, 0);
	mark_cells(_table, MAX_ROWS_ST - 1, MAX_ROWS_ST - 1, 'a', 'z', MAX_ROWS_ST-1);
	mark_cells(_table, MAX_ROWS_ST - 1, MAX_ROWS_ST - 1, 'A', 'Z', MAX_ROWS_ST-1);
	mark_cells(_table, MAX_ROWS_ST - 1, MAX_ROWS_ST - 1, ' ', ' ', MAX_ROWS_ST-1);
	mark_cells(_table, MAX_ROWS_ST - 1, MAX_ROWS_ST - 1, '\"', '\"', 7);
	mark_cells(_table, MAX_ROWS_ST - 1, MAX_ROWS_ST - 1, '.', '.', 7);
	mark_cells(_table, MAX_ROWS_ST - 1, MAX_ROWS_ST - 1, 0, 0, 1);


	//sets row 10 to space space is always set as a pass state
	mark_cells(_table, 10, 10, ' ', ' ', Space);
	mark_cells(_table, 10, 10, 0, 0, 1);

	//row 4-6 reserved for symbols 4 pass, 5 neutral, 6 fail
	mark_cells(_table, 4, 6, "<>*&^%$#@_+-=~", Symbol);
	mark_cells(_table, 4, 4, 0, 0, 1);
	mark_cells(_table, 5, 5, 0, 0, 0);

	//row 11 reserved for puncuation always a pass.
	mark_cells(_table, 11, 11, "';:{}[](),.?/!", Puncuation);
	mark_cells(_table, 11, 11, '\"', '\"', MAX_ROWS_ST - 1);
	mark_cells(_table, 11, 11, 0, 0, 1);
}

bool STokenizer::get_token(int start_state, string& token) {
	if (_buffer[_pos] > 0) {
		//123 aa b
		start_state = _table[start_state][_buffer[_pos]];
	} else {
		start_state = 0;
	}

	int new_state = start_state, startingPos = _pos, pass = _pos;

	//while state is a not a fail state and  
	//currrent state is not a fail state continue looping
	while (_table[new_state][0] != -1 && new_state != -1) {
		if (_buffer[_pos] == 0) {
			break;
		}
		new_state = _table[new_state][_buffer[_pos]];
		//1 is considered a pass state so if our current state is
		//a pass then we save that position separatly
		if (_table[new_state][0] == 1) {
			pass = _pos;
		}
		_pos++;
	}

	//this returns us to the last pass state and adds one so that 
	//we are on the next character
	_pos = pass + 1;

	//add characters to the token one by one 
	while (startingPos < _pos) {
		token.push_back(_buffer[startingPos]);
		startingPos++;
	}
	
	//if the token is blank that means we didnt find any character 
	//so it returns false
	return (token != "");
}

STokenizer& operator>>(STokenizer& s, Token& t) {
	string temp = "";
	if (s.get_token(t.type(), temp)) {
		t = Token(temp, s._table[0][temp[0]]);
	}

	return s;
}