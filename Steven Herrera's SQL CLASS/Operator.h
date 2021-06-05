#ifndef OPERATOR_H_
#define OPERATOR_H_

#include <iostream>
#include <string>

using namespace	std;

class Operator_SY
{
public:
	Operator_SY(string op);
	string _op;
	int _precidence;
private:

};

Operator_SY::Operator_SY(string op)
{
	_op = op;
	if (_op == ">=") {
		_precidence = 3;
	} else if (_op == "<=") {
		_precidence = 3;
	} else if (_op == "<") {
		_precidence = 3;;
	} else if (_op == ">") {
		_precidence = 3;
	}else if (_op == "=") {
		_precidence = 3;
	} else if (_op == "and") {
		_precidence = 2;
	} else if (_op == "or") {
		_precidence = 1;
	} else {
		_precidence = 0;
	}
}


#endif // !OPERATOR_H_
