#include "token.h"
#include <iostream>

using namespace std;
Token::Token() {
	_token = "";
	_type = 0;
}

Token::Token(string str, int type) {
	_token = str;
	_type = type;
}

string Token::token_str() {
	return _token;
}

string Token::type_string() {
	switch (_type) {
	case Number:
		return "Number";
		break;
	case Symbol:
		return "Unknown";
		break;
	case Word:
		return "ALPHA";
		break;
	case Space:
		return "Space";
		break;
	case Puncuation:
		return "Puncuation";
		break;
	default:
		return "Unknown";
		break;
	}
}

int Token::type() {
	return _type;
}

ostream& operator<<(ostream& outs, const Token& t) {
	outs << "|" << t._token << "|" ;
	return outs;
}

