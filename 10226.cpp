//注意使用setprecision(4) include<iomanip>
#include<iostream>
#include<iomanip>
#include<map>
#include<string>
using namespace std;
int main() {
	int testCases;
	cin >> testCases;
	getchar();
	getchar();
	while (testCases--) {
		map<string, int> record;
		string treeName;
		int totalTreeNumber = 0;
		while (getline(cin, treeName)) {
			if (treeName.compare("") == 0) {
				break;
			}
			record[treeName]++;
			totalTreeNumber++;
		}
		for (map<string, int>::iterator i= record.begin(); i != record.end(); i++) {
			cout << i->first << " " << fixed << setprecision(4) << i->second * 100.0 / totalTreeNumber << endl;
		}
		if (testCases != 0) {
			cout<< endl;
		}
		 
	}
	system("pause");
	return 0;
}
