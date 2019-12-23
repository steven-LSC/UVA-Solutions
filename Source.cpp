#include<iostream>
#include<map>
#include<list>
#include<vector>
#include<fstream>
using namespace std;
list<int> ans;
vector<int> situation;
multimap<int, int> graph;
void DFS(int u) {
	situation[u] = 1;
	for (multimap<int, int>::iterator it = graph.lower_bound(u); it != graph.upper_bound(u); it++) {
		if (situation[it->second] == 0) {
			DFS(it->second);
		}
	}
	situation[u] = 2;
	ans.push_front(u);
}
int main() {
	int num_member, num_edge;
	while (cin >> num_member >> num_edge) {
		if (!num_member && !num_edge) {
			break;
		}
		graph.clear();
		ans.clear();
		situation.clear();
		situation.assign(num_member + 1, 0); //1-num_member
		int a, b;
		for (int i = 0; i < num_edge; i++) {
			cin >> a >> b;
			graph.insert(pair<int, int>(a, b));
		}
		for (int i = 1; i <= num_member; i++) {
			if (situation[i] == 0) {
				DFS(i);
			}
		}
		for (list<int>::iterator it = ans.begin(); it != ans.end(); it++) {
			
			if (it != --ans.end()) {
				cout << *it << " ";
			}
			else {
				cout << *it;
			}
		}
		cout << endl;
	}
	return 0;
}