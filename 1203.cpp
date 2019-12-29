#include<iostream>
#include<string>
#include<set>
#include<queue>
using namespace std;
struct Item {
	int num, period, cost;
	bool operator > (const Item &a) const{
		return cost < a.cost || (cost == a.cost && num < a.num);
	}
};
int main() {
	string input;
	multiset<Item,greater<Item>> member;
	Item temp;
	while (cin >> input && input != "#") {
		int num, period;
		cin >> num >> period;
		
		temp.num = num;
		temp.period = period;
		temp.cost = period;
		member.insert(temp);
	}
	int times;
	cin >> times;
	while (times--) {
		cout << (*member.begin()).num << endl;
		temp = (*member.begin());
		temp.cost += temp.period;
		member.erase(member.begin());
		member.insert(temp);
	}
	return 0;
}