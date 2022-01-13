#include <iostream>
#include <fstream>
#include <bitset>
#include <array>

#include "bitsquare.hpp"


using namespace std;



class BitCube {
	private:
		array<BitSquare, 6> faces;
	public:
		BitCube(unsigned char *chars) { // initialize each face of the cube
			faces[0] = BitSquare(chars);
			faces[1] = faces[0];
			faces[1].flipx();
			faces[2] = faces[1];
			faces[2].flipy();
		}
		void print(); // print all faces that are not empty
		void write(string fname);
};
void BitCube::print() {
	for (int i = 0; i < 6; i++) {
		if (!(faces[i] == BitSquare())) {
			faces[i].print();
			cout << endl;
		}
	}
}
void BitCube::write(string fname) {
	ofstream fout;
	fout.open(fname);

	array<unsigned char, 2> tmpchar;
	for(int i = 0; i < faces.size(); i++) {
		if (!(faces[i] == BitSquare())) {
			tmpchar = faces[i].charOut();
			fout << tmpchar[0] << tmpchar[1];
		}
	}

	fout.close();
}


int main() {

	unsigned char chars[2] = {'a', 'b'};

	BitCube data(chars);
	data.print();

	data.write("../out.dat");

	cout << bitset<8>('a') << endl;
	cout << bitset<8>('b') << endl;
}