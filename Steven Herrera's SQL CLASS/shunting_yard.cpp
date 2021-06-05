// shunting_yard.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SY.h"

using namespace std;

int main()
{
    Vector<string> s = { "last","=","jones","or","last","=","bob","and","start","=","square"};
    cout << "original vector: ";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << "\n\n";
    SY sy(s);
    Queue<string>temp;
    temp = sy.getShunted();
    cout << "\n\n\n" << temp;
}
