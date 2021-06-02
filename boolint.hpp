#pragma once

#include <iostream>
#include <vector>

using namespace std;

int booltoint(vector<bool> input) {
	cout << input.size() << endl;

	int mult = 1;
	int out = 0;
	for(int i = input.size(); i > 0; i--) {
		out += input[i] * mult;
		mult *= 2;
	}
	
	return out;
}