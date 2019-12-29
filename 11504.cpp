#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct Node
{
	int d = 0;
	int low = 0;
	int component_id;
};
multimap<int, int>graph;
map<int, Node> situation;
vector<int> my_stack;
vector<vector<int>> component;
vector<int> num_component_inedge;
void Strong_connect(int &time,int u) {
	situation[u].d = situation[u].low = ++time;
	my_stack.push_back(u);
	for (multimap<int, int>::iterator it = graph.lower_bound(u); it != graph.upper_bound(u); it++) {
		if (situation[it->second].d == 0) {
			Strong_connect(time, it->second);
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
			situation[w].component_id = component.size();
		} while (w != u);
		component.push_back(current_component);
	}
}
int main() {
	int test_case;
	cin >> test_case;
	while (test_case--) {
		graph.clear();
		situation.clear();
		component.clear();
		my_stack.clear();
		Node temp;
		int num_member, num_edge, a, b, time = 0, ans = 0;
		cin >> num_member >> num_edge;
		for (int i = 1; i <= num_member; i++) {
			situation[i] = temp;
		}
		for (int i = 0; i < num_edge; i++) {
			cin >> a >> b;
			graph.insert(pair<int, int>(a, b));
		}
		for (int i = 1; i <= num_member; i++) {
			if (situation[i].d == 0) {
				Strong_connect(time, i);
			}
		}
		num_component_inedge.clear();
		num_component_inedge.assign(component.size(), 0);
		for (multimap<int, int>::iterator it = graph.begin(); it != graph.end(); it++) {
			if (situation[it->first].component_id != situation[it->second].component_id) {
				num_component_inedge[situation[it->second].component_id]++;
			}
		}
		for (int i = 0; i < num_component_inedge.size(); i++) {
			if (num_component_inedge[i] == 0) {
				ans++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}