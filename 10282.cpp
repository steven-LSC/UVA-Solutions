#include<iostream>
#include<sstream>
#include<map>
#include<string>
using namespace std;
int main() {
	map<string, string> dictionary;
	string input;
	string first;
	string second;
	while (getline(cin, input)) {
		if (input == "") {
			break;
		}
		istringstream seperate(input);
		seperate >> first >> second;
		dictionary[second] = first;
	}
	while (cin >> input) {
		map<string, string>::iterator it;
		it = dictionary.find(input);
		if (it != dictionary.end()) {
			cout << it->second << endl;
		}
		else {
			cout << "eh" << endl;
		}
	}
	system("pause");
	return 0;
}