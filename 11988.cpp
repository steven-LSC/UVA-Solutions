#include<iostream>
#include<string>
#include<list>
using namespace std;
int main() {
	string input;
	while (getline(cin, input)) {
		list<char> text;
		list<char>::iterator it = text.begin();
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '[') {
				it = text.begin();
			}
			else if (input[i] == ']') {
				it = text.end();
			}
			else {
				text.insert(it, input[i]);
			}
		}
		for (it = text.begin(); it != text.end(); it++) {
			cout << *it;
		}
		cout << endl;
	}
}