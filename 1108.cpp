//沒有cutpoint:component.size() * (component.size() - 1) / 2
//一個cutpoint:component.size()
//2個以上不用放
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<stack>
#include<vector>
using namespace std;

struct Node
{
	int d = 0;
	int low = 0;
	int num_children = 0;
	int parent = -1;
	bool cut = false;
};

multimap<int, int> graph;
vector<Node> situation;//1-(my_max+1)
stack<pair<int, int>> my_stack;
vector<set<int>> component;

void articulation(int &time,int current) {
	time++;
	situation[current].d = time;
	situation[current].low = time;
	for (multimap<int, int>::iterator it = graph.lower_bound(current); it != graph.upper_bound(current); it++) {
		if (situation[it->second].d == 0) {
			situation[current].num_children++;
			situation[it->second].parent = current;
			my_stack.push(pair<int,int>(current, it->second));
			articulation(time,it->second);
			situation[current].low = min(situation[current].low, situation[it->second].low);
			if (situation[current].parent != -1 && situation[it->second].low >= situation[current].d) {
				situation[current].cut = true;
			}
			if (situation[it->second].low >= situation[current].d) {
				pair<int, int> w;
				set<int> temp_set;
				do
				{
					w = my_stack.top();
					my_stack.pop();
					temp_set.insert(w.first);
					temp_set.insert(w.second);
				} while (!my_stack.empty() && w != pair<int,int>(current, it->second));
				component.push_back(temp_set);
			}
		}
		else if (it->second != situation[current].parent) {
			situation[current].low = min(situation[current].low, situation[it->second].d);
			if (situation[current].d > situation[it->second].d) {
				my_stack.push(pair<int, int>(current, it->second));
			}
		}
	}
}
int main() {
	int num_case;
	int count_case = 0;
	while (cin >> num_case && num_case)
	{
		graph.clear();
		while (!my_stack.empty())
		{
			my_stack.pop();
		}
		component.clear();

		count_case++;
		int a, b, time = 0, my_max = 0;

		for (int i = 0; i < num_case; i++) {
			cin >> a >> b;
			graph.insert(pair<int, int>(a, b));
			graph.insert(pair<int, int>(b, a));
			my_max = max(my_max, max(a, b));
		}

		situation.clear();
		situation.resize(my_max + 1);

		for (int i = 1; i <= my_max; i++) {
			if (graph.find(i) != graph.end() && situation[i].d == 0) {
				articulation(time,i);
				if (situation[i].num_children > 1) {
					situation[i].cut = true;
				}
			}
		}

		long long int ans_case = 1;
		long long int num_tunnel = 0;
		int temp;
		
		if (component.size() == 1) {
			num_tunnel = 2;
			ans_case = ((component[0].size() * (component[0].size() - 1)) / 2);
		}
		else {
			for (int i = 0; i < component.size(); i++) {
				temp = 0;
				for (set<int>::iterator it = component[i].begin(); it != component[i].end(); it++) {
					if (situation[*it].cut == true) {
						temp++;
					}
					if (temp > 1) {
						break;
					}
				}
				if (temp == 1) {
					num_tunnel++;
					ans_case *= (long long)(component[i].size() - 1);
				}
			}
		}
		cout << "Case " << count_case << ": " << num_tunnel << " " << ans_case << endl;
	}
	return 0;
}
