#include<iostream>
#include<set>
using namespace std;
int main() {
	int days;
	while (cin >> days && days) {
		long long int amount, temp, total = 0;
		multiset<int> bill;
		multiset<int>::iterator it;
		for (int i = 0; i < days; i++) {
			cin >> amount;
			for (int i = 0; i < amount; i++) {
				cin >> temp;
				bill.insert(temp);
			}
			it = bill.end();
			it--;
			total += (*it - *(bill.begin()));
			bill.erase(it);
			bill.erase(bill.begin());
		}
		cout << total << endl;
	}
	system("pause");
	return 0;
}