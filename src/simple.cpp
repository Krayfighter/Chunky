#include <iostream>
#include <vector>

using namespace std;


class Chunker {
	vector<string> data;
	public:
		Chunker(string input, int chunksize = 4, char filler = '$') {

			// add 'filler' to input until its length is evenly divisible by 'chunksize'
			for(int i = 0; i < input.size()%chunksize; i++) {input += filler;}

			// split input into 'chunks' and add it to data
			for(int i = 0; i < input.size()/chunksize; i++) {
				data.push_back("");
				for(int o = 0; o < chunksize; o++) {data[i] += input[i*chunksize+o];}
			}
		}

		void set(vector<string> data) {this->data = data;}
		vector<string> set() {return this->data;}

		// print the contents of private vector<strign> (data)
		void print() {for(string chunk: data) {cout << chunk << endl;}}

		vector<string> invert(vector<string> input) {
			vector<string> _data = {};
			for(int i = input.size(); i > 0; i--) {_data.push_back(input[i-1]);}
			return _data;
		}void invert() {data = invert(data);} // overload the invert function to allow invert on sub-vectors
};

int main() {
	Chunker text = Chunker("Hello, World!", 4);
	text.invert();
	text.print();
}