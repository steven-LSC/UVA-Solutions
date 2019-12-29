#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main() {
	int count = 1;
	int people, command;
	while (cin >> people >> command && people&& command) {
		
		list<int> line;
		cout << "Case " << count++ << ":" << endl;
		for (int i = 1; i <= min(people,command); i++) {
			line.push_back(i);
		}
		for (int i = 0; i < command; i++) {
			char input, temp;
			cin >> input;
			if (input == 'N') {
				cout << line.front() << endl;
				line.push_back(line.front());
				line.pop_front();
			}
			else if (input == 'E') {
				long int who;
				cin >> who;
				for (list<int>::iterator it = line.begin(); it != line.end(); it++) {
					if (*it == who) {
						line.erase(it);
						break;
					}
				}
				line.push_front(who);
			}
		}
	}
	system("pause");
	return 0;
}