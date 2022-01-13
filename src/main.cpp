#include <iostream>
// #include <vector>
#include <array>
#include <bitset>


using namespace std;

// Square grid from 2 bytes (unsigned chars)
class BitSquare {
	private:
		array<bitset<4>, 4> square = {0, 0, 0, 0}; // 4 item std::array of 4 bit bitsets
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
		bool operator==(const BitSquare &rhs); // check if two bitsquares are equal
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
bool BitSquare::operator==(const BitSquare &rhs) {
	return this->square == rhs.square; // compare dereferenced `square` of each bitsquare
}


class BitCube {
	private:
		BitSquare faces[6];
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


int main() {

	unsigned char chars[2] = {'a', 'b'};

	BitCube data(chars);
	data.print();

	cout << bitset<8>('a') << endl;
	cout << bitset<8>('b') << endl;
}