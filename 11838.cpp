#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct Node {
	int d = 0;
	int low = 0;
};
multimap<int, int> graph;
vector<int> my_stack;
map<int, Node> situation;
vector<vector<int>> component;
void StrongConnect(int &time,int u) {
	situation[u].d = situation[u].low = ++time;
	my_stack.push_back(u);
	for (multimap<int, int>::iterator it = graph.lower_bound(u); it != graph.upper_bound(u); it++) {
		if (situation[it->second].d == 0) {
			StrongConnect(time, it->second);
			situation[u].low = min(situation[u].low, situation[it->second].low);
		}
		else if (find(my_stack.begin(), my_stack.end(), it->second) != my_stack.end()) {
			situation[u].low = min(situation[u].low, situation[it->second].d);
		}
	}
	if (situation[u].d == situation[u].low) {
		vector<int> current_component;
		int w;
		do {
			w = my_stack.back();
			my_stack.pop_back();
			current_component.push_back(w);
		} while (w != u);
		component.push_back(current_component);
	}
}
int main() {
	int num_member, num_edge;
	while (cin >> num_member >> num_edge && num_member&& num_edge) {
		graph.clear();
		my_stack.clear();
		situation.clear();
		component.clear();
		Node temp;
		for (int i = 1; i <= num_member; i++) {
			situation[i] = temp;
		}
		int a, b, c, time = 0;
		for (int i = 0; i < num_edge; i++) {
			cin >> a >> b >> c;
			graph.insert(pair<int, int>(a, b));
			if (c == 2) {
				graph.insert(pair<int, int>(b, a));
			}
		}
		for (int i = 1; i <= num_member; i++) {
			if (situation[i].d == 0) {
				StrongConnect(time, i);
			}
		}
		if (component.size() == 1) {
			cout << 1 << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}