#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int main() {
	int number;
	while (cin >> number && number) {
		while (true) {
			int temp;
			stack<int> station;
			queue<int> input;
			cin >> temp;
			if (temp == 0) {
				break;
			}
			input.push(temp);
			for (int i = 1; i < number; i++) {
				cin >> temp;
				input.push(temp);
			}
			for (int i = 1; i <= number; i++) {
				station.push(i);
				while (!station.empty() && station.top() == input.front()) {
					station.pop();
					input.pop();
				}
			}
			if (station.empty()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		cout << endl;
	}
	return 0;
}