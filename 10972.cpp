//孤立的點+縮點後沒有橋的點+ceil(有橋的點/2.0)
#include<iostream>
#include<map>
#include<algorithm>
#include<fstream>
#include<vector>
#include<stack>
#include<math.h>
#include<stdio.h>
using namespace std;
struct Node
{
	int d = 0;
	int low = 0;
	int parent = -1;
	int num_connect_bridge = 0;
};

multimap<int, int> graph;
vector<Node> situation;
stack<int> my_stack;
vector<vector<int>> component;
vector<pair<int, int>> my_bridge;

void bridge(int& time, int u) {
	situation[u].d = situation[u].low = ++time;
	my_stack.push(u);
	for (multimap<int, int>::iterator it = graph.lower_bound(u); it != graph.upper_bound(u); it++) {
		if (situation[it->second].d == 0) {
			situation[it->second].parent = u;
			bridge(time, it->second);
			situation[u].low = min(situation[u].low, situation[it->second].low);
			if (situation[it->second].low > situation[u].d) {
				situation[u].num_connect_bridge++;
				situation[it->second].num_connect_bridge++;
				vector<int> current_component;
				int w;
				do
				{
					w = my_stack.top();
					my_stack.pop();
					current_component.push_back(w);
				} while (w != it->second);
				component.push_back(current_component);
			}
		}
		else if (it->second != situation[u].parent) {
			situation[u].low = min(situation[u].low, situation[it->second].d);
		}
	}
}
int main() {
	int num_member;
	int num_birdge;
	while (cin >> num_member >> num_birdge)
	{
		graph.clear();
		situation.clear();
		situation.resize(num_member + 1);
		while (!my_stack.empty())
		{
			my_stack.pop();
		}
		component.clear();
		my_bridge.clear();

		int a, b, time = 0, num_component_bridge = 0;
		for (int i = 0; i < num_birdge; i++) {
			cin >> a >> b;
			graph.insert(pair<int, int>(a, b));
			graph.insert(pair<int, int>(b, a));
		}
		for (int i = 1; i < num_member; i++) {
			if (situation[i].d == 0) {
				bridge(time, i);
				vector<int> current_component;
				while (!my_stack.empty())
				{
					current_component.push_back(my_stack.top());
					my_stack.pop();
				}
				component.push_back(current_component);
			}
		}
		int connect = 0;
		for (int i = 0; i < component.size(); i++) {
			connect += component[i].size();
		}
		int isolation = num_member - connect;
		//ofstream outfile("ans.txt", ios::app);
		if (isolation + component.size() == 1) {
			//outfile << 0 << endl;
			cout << 0 << endl;
		}
		else
		{
			float count[2] = {};
			for (int i = 0; i < component.size(); i++) {
				int temp = 0;
				for (int x = 0; x < component[i].size(); x++) {
					temp += situation[component[i][x]].num_connect_bridge;
				}
				if (temp <= 1) {
					count[temp]++;
				}
			}
			//outfile<< isolation + count[0] + ceil(count[1] / 2.0) << endl;
			cout << isolation + count[0] + ceil(count[1] / 2.0) << endl;
		}
	}
	return 0;
}
