#include <iostream>
#include <bitset>

#include "bitarray.hpp"

using namespace std;


int main() {
	cout << bitset<8>('i') << endl;
	bitarray out('i');
	out.print();
	bool *bp;
	bp = out.get();
	for(int i = 0; i < 8; i++) {cout << bp[i];}cout << endl;
}