#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<map>
#include<set>
using namespace std;
struct node
{
	int d = 0;
	int low = 0;
	int parent = -1;
	bool cut = false;
	int numChildren = 0;
	set<int>num_component;
};
multimap<int, int> graph; 
vector<node> situation;
vector<pair<int, int>> my_stack;
void articulationPoint(int currentNode, int& time,int &cnt) {
	time++;
	situation[currentNode].d = time;
	situation[currentNode].low = time;
	for (multimap<int, int>::iterator it = graph.lower_bound(currentNode); it != graph.upper_bound(currentNode); it++) {
		if (situation[it->second].d == 0) {
			situation[currentNode].numChildren++;
			situation[it->second].parent = currentNode;
			my_stack.push_back(pair<int, int>(currentNode, it->second));
			articulationPoint(it->second, time, cnt);
			situation[currentNode].low = min(situation[currentNode].low, situation[it->second].low);
			if (situation[currentNode].d <= situation[it->second].low) {
				if (situation[currentNode].parent != -1) {
					situation[currentNode].cut = true;
				}
				pair<int, int> temp_pair;
				do {
					temp_pair = my_stack.back();
					my_stack.pop_back();
					situation[temp_pair.first].num_component.insert(cnt);
					situation[temp_pair.second].num_component.insert(cnt);
				} while (temp_pair != pair<int, int>(currentNode, it->second));
				cnt++;
			}
		}
		else if (situation[currentNode].parent != it->second) {
			situation[currentNode].low = min(situation[currentNode].low, situation[it->second].d);
			if (situation[currentNode].d > situation[it->second].d) {
				my_stack.push_back(pair<int, int>(currentNode, it->second));
			}
		}
	}
}
int main() {
	int n, m;
	while (cin >> n >> m && n&& m) {
		int a, b;
		graph.clear();
		my_stack.clear();
		while (cin >> a >> b && a != -1 && b != -1) {
			graph.insert(pair<int, int>(a, b));
			graph.insert(pair<int, int>(b, a));
		}
		node temp_node;
		situation.clear();
		situation.assign(n, temp_node);
		int time = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (situation[i].d == 0) {
				articulationPoint(i, time, cnt);
				if (situation[i].numChildren > 1) {
					situation[i].cut = true;
				}
			}
		}
		cnt = 0;
		multimap<int, int> ans;
		for (int i = n - 1; i >= 0; i--) {
			ans.insert(pair<int, int>(situation[i].num_component.size(), i));
		}
		for (multimap<int, int>::reverse_iterator it = ans.rbegin(); it != ans.rend(); it++) {
			cnt++;
			if (cnt <= m) {
				cout << it->second << " " << it->first << endl;
			}
		}
		cout << endl;
	}
}