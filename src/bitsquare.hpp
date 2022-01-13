#pragma once

#include <iostream>
#include <bitset>
#include <array>

using namespace std;

// Square grid from 2 bytes (unsigned chars)
class BitSquare {
	private:
		array<bitset<4>, 4> square = {0, 0, 0, 0}; // 4 item std::array of 4 bit bitsets
		enum ops {
			flipx,
			flipy
		};
	public:
		BitSquare(unsigned char *chars, int ix = 0, int iy = 1) {
			// initialize each bitset to its half-byte (4 bits)
			square[0] = bitset<4>(chars[ix] >> 4);
			square[1] = bitset<4>(chars[ix] & 0xff);
			square[2] = bitset<4>(chars[iy] >> 4);
			square[3] = bitset<4>(chars[iy] & 0xff);
		}
		BitSquare() {return;} // default constructor
		void flipx(); // flip the square over the x axis (reflection)
		void flipy(); // flip the square over the y axis (relfection)
		void print(); // print the square as a grid
		void parse(); // parse an input as an encryption key
		bool operator==(const BitSquare &rhs); // check if two bitsquares are equal
		array<unsigned char, 2> charOut(); // return currernt square as 2 unsigned chars
};
void BitSquare::flipx() {
	// create a temporary btisquare
	bitset<4> tmp[4];
	for (int i = 0; i < 4; i++) { // iterate for each bitset in the square
		int o = 3; // iterate backwards starting at the last bit of `square[i]`
		int e = 0; // iterate forwards starting at the first bit of `tmp[i]`
		while (o >= 0) {
			tmp[i].set(o, square[i][e]); // set opposite side of one bitset to the other
			o--;
			e++;
		}
	}
	for (int i = 0; i < 4; i++) { // deep copy tmp into square
		square[i] = tmp[i];
	}
}
void BitSquare::flipy() {
	array<bitset<4>, 4> tmp; // tmp array 4 by bitset 4 (4x4)
	int i = 3; // iteration of square
	int o = 0; // iteration of tmp
	while (i >= 0) {
		tmp[o] = square[i]; // copy opposing side of square to tmp
		i--;
		o++;
	}
	square = tmp; // deep copy tmp to square
}
void BitSquare::print() {
	for (int i = 0; i < 4; i++) {
		cout << "|";
		for (int o = 0; o < 4; o++) {
			cout << square[i].test(o) << "|";
		}
		cout << endl;
	}
}
void BitSquare::parse() {
	string tmp = "key";
	// 
}
bool BitSquare::operator==(const BitSquare &rhs) {
	return this->square == rhs.square; // compare dereferenced `square` of each bitsquare
}
array<unsigned char, 2> BitSquare::charOut() {
	// append 2 bitsets<4> and convert to unsigned char then add to `out`
	array<unsigned char, 2> out;
	out[0] = (unsigned char)(square[0].to_ulong() << 4)+(square[1].to_ulong());
	out[1] = (unsigned char)(square[2].to_ulong() << 4)+(square[3].to_ulong());
	return out;
}