#include <exception>
#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>

#include "err.hpp"
#include "boolint.hpp"

using namespace std;


struct bitmap {
	vector<bitset<8> > data = {0}; // space is required before the last '>' before C++11
	bitmap(string word) {
		if(word.size() > 8) {throw String_Parameter_Too_Long();}
		if(word.size() < 8) {throw String_Parameter_Too_Short();}
		for(int i = 0; i < 8; i++) {
			data[i] = bitset<8>(word[i]);
		}
	}
	bitmap() {}
	int size() {return data.size();}
	bitset<8> operator[](int index) {return data[index];}
	void operator=(string word) {
		if(word.size() > 8) {throw String_Parameter_Too_Long();}
		if(word.size() < 8) {throw String_Parameter_Too_Short();}
		for(int i = 0; i < 8; i++) {
			data[i] = bitset<8>(word[i]);
		}
	}
};

// handles 8 by 8 bit grid movemoents
class Handler {
	bitmap data = string("        ");
	public:
		Handler(string data) {this->data = data;}
		void print() {for(int i = 0; i < 8; i++) {cout << data[i] << '|';}} // print bits to console
		void printi() {for(int i = 0; i < 8; i++) {cout << (int)(data[i].to_ulong()) << '|';}} // print bits as int
		void printc() {for(int i = 0; i < 8; i++) {cout << (char)(int)(data[i].to_ulong()) << '|';}} //print bits as char
		void printflat() {for(int i = 0; i < 8; i++) {cout << '|' << data[i] << '|' << endl;}} // print bits in lateral format
		void rotate(bool clock = true) { // rotate 90 degrees clockwise by default
			bitmap tmp;
			cout << tmp.size();
				// for(int i = 0; i < 8; i++) {
				// 	for(int i = 8; i > 0; i--) {
				// 		tmp[i][o]
				// 	}
				// }
			// complete this function
		}
		void flip(bool flipx = true); // flips on x axis by default
};


void printall(Handler* bithandler) {
	bithandler->print();
	cout << endl;
	bithandler->printi();
	cout << endl;
	bithandler->printc();
	cout << endl;
}

int main() {
	// Handler bits("aiden   ");
	// printall(&bits);
	// bits.rotate();
	// bits.printflat();
	vector<bool> var = {0, 0, 0, 0, 1, 0, 0, 0};
	cout << bitset<8>(8) << endl;
	booltoint(var);
}