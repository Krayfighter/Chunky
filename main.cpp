#include <iostream>
#include <vector>

using namespace std;


class Chunker {
	vector<string> data;
	public:
		Chunker(string input, int chunksize = 4, char filler = '$') {
			for(int i = 0; i < input.size()%chunksize; i++) {input += filler;}
			for(int i = 0; i < input.size()/chunksize; i++) {
				data.push_back("");
				for(int o = 0; o < chunksize; o++) {data[i] += input[i*chunksize+o];}}
		}
		void print() {for(string chunk: data) {cout << chunk << endl;}}
};

int main() {
	Chunker text = Chunker("hello", 2);
	text.print();
}