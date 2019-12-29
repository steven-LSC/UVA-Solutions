#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<deque>
using namespace std;
void dfs(deque<char>& src, deque<char>& des, vector<char>& order, stack<char>& bridge) {
	if (!src.empty()) {
		//走到底
		bridge.push(src.front());
		src.pop_front();
		order.push_back('i');
		dfs(src, des, order, bridge);
		//復原
		src.push_front(bridge.top());
		order.pop_back();
		bridge.pop();
	}
	if (!bridge.empty() && des[des.size()-bridge.size()-src.size()] == bridge.top()) {
		order.push_back('o');
		char temp = bridge.top();
		bridge.pop();
		dfs(src, des, order, bridge);
		bridge.push(temp);
		order.pop_back();
	}
	if (bridge.empty() && src.empty()) {
		vector<char>::iterator it = order.begin();
		for (; it != --order.end(); it++) {
			cout << *it << " ";
		}
		cout << *it << endl;
	}
}
int main() {
	string str1;
	string str2;
	while (cin >> str1 >> str2) {
		cout << "[" << endl;
		if (str1.length() == str2.length() && !str1.empty()) {
			deque<char> src(str1.begin(), str1.end());
			deque<char> des(str2.begin(), str2.end());
			vector<char> order;
			stack<char> bridge;
			dfs(src, des, order, bridge);
			
		}
		cout << "]" << endl;
	}
	return 0;
}