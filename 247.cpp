#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<stack>
#include<list>
#include<deque>
#include<map>
using namespace std;
struct Node
{
	int d = 0;
	int low = 0;
};
multimap<string, string> graph;
map<string,Node> situation; //(d,low)
vector<string> my_stack;
vector<vector<string>> component;
void SCC(int& time, string u) {
	time++;
	situation[u].d = situation[u].low = time;
	my_stack.push_back(u);
	for (multimap<string, string>::iterator it = graph.lower_bound(u); it != graph.upper_bound(u); it++) {
		if (situation[it->second].d == 0) {
			SCC(time, it->second);
			situation[u].low = min(situation[u].low, situation[it->second].low);
		}
		else if (find(my_stack.begin(), my_stack.end(), it->second) != my_stack.end()) {
			situation[u].low = min(situation[u].low, situation[it->second].d);
		}
	}
	if (situation[u].d == situation[u].low) {
		vector<string> current_component;
		string w;
		do
		{
			w = my_stack.back();
			my_stack.pop_back();
			current_component.push_back(w);
		} while (w != u);
		component.push_back(current_component);
	}
}
int main() {
	int num_member, num_edge, count = 0;
	while (cin >> num_member >> num_edge) {
		count++;
		if (!num_member && !num_edge) {
			break;
		}
		graph.clear();
		situation.clear();
		while (!my_stack.empty())
		{
			my_stack.pop_back();
		}
		component.clear();
		int time = 0;
		string a, b;
		Node temp;
		for (int i = 0; i < num_edge; i++) {
			cin >> a >> b;
			graph.insert(pair<string, string>(a, b));
			situation[a] = temp;
			situation[b] = temp;
		}
		for (map<string, Node>::iterator it = situation.begin(); it != situation.end(); it++) {
			if (it->second.d == 0) {
				SCC(time, it->first);
			}
		}
		cout << "Calling circles for data set " << count << ":" << endl;
		for (int i = 0; i < component.size(); i++) {
			for (int x = 0; x < component[i].size(); x++) {
				if (x != component[i].size() - 1) {
					cout << component[i][x] << ", ";
				}
				else {
					cout << component[i][x];
				}
			}
			cout << endl;
		}
	}
	return 0;
}