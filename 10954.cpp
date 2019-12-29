#include<iostream>
#include<set>
using namespace std;
int main() {
	int cases;
	while (cin >> cases && cases) {
		multiset<int> number;
		int temp,total=0,hight;
		for (int i = 0; i < cases; i++) {
			cin >> temp;
			number.insert(temp);
		}
		
		temp = 0;
		multiset<int>::iterator it1;
		multiset<int>::iterator it2;
		while (number.size() != 1) {
			it1 = number.begin();
			it2 = number.begin();
			it2++;
			total += *it1 + *it2;
			number.insert(*it1+*it2); //一定比各自大，所以可以直接放
			number.erase(it1);
			number.erase(it2);
		}
		cout << total << endl;
	}
}