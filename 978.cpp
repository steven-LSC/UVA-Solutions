#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int B, SG, SB, temp;
		multiset<int> green, blue;
		cin >> B >> SG >> SB;
		for (int x = 0; x < SG; x++) {
			cin >> temp;
			green.insert(temp);
		}
		for (int x = 0; x < SB; x++) {
			cin >> temp;
			blue.insert(temp);
		}
		
		while (blue.empty() == false && green.empty() == false) {
			multiset<int>::iterator greenMax, blueMax;
			vector<int> greenMember, blueMember;
			int bigB;
			if (blue.size() > green.size()) {
				bigB = green.size();
			}
			else {
				bigB = blue.size();
			}
			for (int x = 0; x < bigB; x++) {

				if (x == B) {
					bigB = B;
					break;
				}
				greenMax = green.end(), blueMax = blue.end();
				greenMax--; blueMax--;
				
				greenMember.push_back(*greenMax);
				blueMember.push_back(*blueMax);
				
				green.erase(greenMax);
				blue.erase(blueMax);
			}
			for (int i = 0; i < bigB; i++) {
				if (greenMember[i] > blueMember[i]) {
					greenMember[i] -= blueMember[i];
					blueMember[i] = 0;
				}
				else if (greenMember[i] < blueMember[i]) {
					blueMember[i] -= greenMember[i];
					greenMember[i] = 0;
				}
				else {
					blueMember[i] = 0;
					greenMember[i] = 0;
				}
			}
			for (int i = 0; i < bigB; i++) {
				if (greenMember[i] != 0) {
					green.insert(greenMember[i]);
				}
				if (blueMember[i] != 0) {
					blue.insert(blueMember[i]);
				}
			}
		}
		if (blue.empty() == false) {
			cout << "blue wins" << endl;
			for (multiset<int>::reverse_iterator it = blue.rbegin(); it != blue.rend(); it++) {
				cout << *it << endl;
			}
		}
		else if(green.empty()==false){
			cout << "green wins" << endl;
			for (multiset<int>::reverse_iterator it = green.rbegin(); it != green.rend(); it++) {
				cout << *it << endl;
			}
		}
		else {
			cout << "green and blue died" << endl;
		}
		if (i != cases - 1) {
			cout << endl;
		}
	}
	system("pause");
	return 0;
}