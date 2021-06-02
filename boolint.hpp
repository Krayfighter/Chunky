#pragma once

#include <iostream>

using namespace std;

int booltoint(bool *input) {
	cout << typeid(input).name() << endl;
	cout << typeid(new bool).name() << endl;
}