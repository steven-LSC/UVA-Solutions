//計算cutpoint數量
#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>
using namespace std;
struct node
{
	int d;
	int low;
	int parent;
	bool cut;
	int numChildren;
};
void articulationPoint(multimap<int,int> graph,vector<node> &situation,int currentNode,int &time) {
	time++;
	situation[currentNode].d = time;
	situation[currentNode].low = time;
	for (multimap<int, int>::iterator it = graph.lower_bound(currentNode); it != graph.upper_bound(currentNode); it++) {
		if (situation[it->second].d == 0) {
			situation[currentNode].numChildren++;
			situation[it->second].parent = currentNode;
			articulationPoint(graph, situation, it->second, time);
			situation[currentNode].low = min(situation[currentNode].low, situation[it->second].low);
			if (situation[currentNode].parent != 0 && situation[currentNode].d <= situation[it->second].low) {
				situation[currentNode].cut = true;
			}
		}
		else if (situation[currentNode].parent != it->second) {
			situation[currentNode].low = min(situation[currentNode].low, situation[it->second].d);
		}
	}
}
int main() {
	int numMember;
	while (cin >> numMember && numMember != 0) {
		string temp1;
		multimap<int, int> graph;
		while (getline(cin, temp1) && temp1 != "0") {
			stringstream ss(temp1);
			int first, temp2;
			ss >> first;
			while (ss >> temp2)
			{
				graph.insert(pair<int, int>(first, temp2));
				graph.insert(pair<int, int>(temp2, first));
			}
		}
		vector<node> situation(numMember + 1);
		for (int i = 1; i < situation.size(); i++) {
			situation[i].d = 0;
			situation[i].low = 0;
			situation[i].parent = 0;
			situation[i].numChildren = 0;
			situation[i].cut = false;
		}
		int time = 0;
		for (int i = 1; i < situation.size(); i++) {
			if (situation[i].d == 0) {
				articulationPoint(graph, situation, i, time);
				if (situation[i].numChildren > 1) {
					situation[i].cut = true;
				}
			}
		}
		int total = 0;
		for (int i = 1; i < situation.size(); i++) {
			if (situation[i].cut == true) {
				total++;
			}
		}
		cout << total << endl;
	}
	return 0;
}
