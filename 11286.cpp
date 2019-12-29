#include<iostream>
#include<sstream>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	int numberOfStudents;

	while (cin >> numberOfStudents && numberOfStudents) {

		map<string, int> dictionary;

		for (; numberOfStudents > 0; numberOfStudents--) {
			string full, temp;
			int buff[5];
			for (int i = 0; i < 5; i++) {
				cin >> buff[i];
			}
			sort(buff, buff + 5);
			for (int i = 0; i < 5; i++) {
				full += to_string(buff[i]);
			}
			temp = full;
			dictionary[temp]++;
		}
		int max = 0, maxNum = 0;
		for (map<string, int>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
			if (it->second > max) {
				max = it->second;
				maxNum = 0;
			}
			if (it->second == max) {
				maxNum += max;
			}
		}
		cout << maxNum << endl;
	}
	system("pause");
	return 0;
}