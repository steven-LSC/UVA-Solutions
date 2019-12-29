#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int main() {

	int cases;
	cin >> cases;
	while (cases--) {
		int amount, temp, maxlen = 0;
		vector<int> totalSnow;
		set<int> uniqueSnow;
		cin >> amount;
		for (int i = 0; i < amount; i++) {
			cin >> temp;
			totalSnow.push_back(temp);
		}
		int L = -1;
		for (int i = 0; i < totalSnow.size(); i++) {
			if (uniqueSnow.count(totalSnow[i]) == 0) {
				uniqueSnow.insert(totalSnow[i]);
				maxlen = max(i - L,maxlen);
			}
			else {
				while (uniqueSnow.count(totalSnow[i]) != 0) {
					L++;
					uniqueSnow.erase(totalSnow[L]);
				}
				uniqueSnow.insert(totalSnow[i]);
			}
		}
		cout << maxlen << endl;
	}
	system("pause");
	return 0;
}