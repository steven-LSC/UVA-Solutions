//計算橋的數量和輸出橋
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
using namespace std;
struct node {
	int d;
	int low;
	int parent;
};
void bridge(multimap<int, int> graph, vector<node>& situation, multiset<pair<int, int>>& ans, int &time, int current) {
	time++;
	situation[current].d = time;
	situation[current].low = time;
	for (multimap<int, int>::iterator it = graph.lower_bound(current); it != graph.upper_bound(current); it++) {
		if (situation[it->second].d == 0) {
			situation[it->second].parent = current;
			bridge(graph, situation, ans, time, it->second);
			situation[current].low = min(situation[current].low, situation[it->second].low);
			if (situation[current].d < situation[it->second].low) {
				(current < it->second) ? ans.insert(pair<int, int>(current, it->second)) : ans.insert(pair<int, int>(it->second, current));
			}
		}
		else if (it->second != situation[current].parent) {
			situation[current].low = min(situation[current].low, situation[it->second].d);
		}
	}
}
int main() {
	int cases;
	while (cin >> cases)
	{
		multimap<int, int> graph;
		multiset<pair<int, int>> ans;
		vector<node> situation(cases);
		int time = 0, temp1, temp2, temp3;
		for (int i = 0; i < cases; i++) {
			situation[i].d = 0;
			situation[i].parent = 0;
			situation[i].low = 0;
			scanf_s("%d (%d)", &temp1, &temp2);
			while (temp2--)
			{
				cin >> temp3;
				graph.insert(pair<int, int>(temp1, temp3));
			}
		}
		for (int i = 0; i < cases; i++) {
			if (situation[i].d == 0) {
				bridge(graph, situation, ans, time, i);
			}
		}
		cout << ans.size() << " critical links" << endl;
		for (multiset<pair<int, int>>::iterator it = ans.begin(); it != ans.end(); it++) {
			cout << it->first << " - " << it->second << endl;
		}
		cout << endl;
	}
}
