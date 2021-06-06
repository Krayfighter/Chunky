#pragma once

#include <vector>
#include <bitset>

using namespace std;


struct bitarray {
	vector<bool> data;
	bitarray() {for(int i = 0; i < 8; i++) {data.push_back(false);}}
	bitarray(char input) {
		auto tmp = bitset<8>(input);
		for(int i = 7; i >= 0; i--) {
			data.push_back(tmp[i]);
		}
	}
	void print() {
		for(auto var: data) {cout << var;}
		cout << endl;
	}
	bool* get() {
		static bool tmp[8];
		for(int i = 0; i < 8; i++) {tmp[i] = data[i];}
		return tmp;
	}
};
