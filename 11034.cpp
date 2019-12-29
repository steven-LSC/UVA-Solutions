#include<iostream>
#include<queue>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int ferryCm, numberOfCars, temp;
		bool isleft = true;
		string sTemp;
		queue<int> left, right;
		vector<int> ferry;
		cin >> ferryCm >> numberOfCars;
		ferryCm *= 100;
		for (int i = 0; i < numberOfCars; i++) {
			cin >> temp >> sTemp;
			if (sTemp == "left") {
				left.push(temp);
			}
			else {
				right.push(temp);
			}
		}
		int count, times = 0;
		while (!left.empty()||!right.empty())
		{
			if (isleft == true) {
				count = 0;
				while (!left.empty() && count + left.front() <= ferryCm) {
					
					count += left.front();
					left.pop();
				}
				isleft = false;
				times++;
			}
			else {
				count = 0;
				while (!right.empty() && count + right.front() <= ferryCm) {
					
					count += right.front();
					right.pop();
				}
				isleft = true;
				times++;
			}
		}
		cout << times << endl;
	}
}