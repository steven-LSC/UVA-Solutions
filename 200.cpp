//一次兩行判斷，找出誰<誰，topological sort
#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <vector>
using namespace std;
void topological(multimap<char, char> graph, map<char, int>& situation, stack<char>& ans, char n)
{
	if (graph.find(n) != graph.end()) {
		for (multimap<char, char>::iterator it = graph.lower_bound(n); it != graph.upper_bound(n); it++) {
			if (situation[it->second] == 1) {
				situation[it->second] = 2;
				topological(graph, situation, ans, it->second);
			}
		}
	}
	if (situation[n] == 2) {
		ans.push(n);
	}

}
int main()
{
	string a, b;
	while (cin >> a) {
		multimap<char, char> graph;
		map<char, int> situation; //1´N¬O¦³³o­ÓÂI 2´N¬O¨«¹L 
		stack<char> ans;
		for (char i = 'A'; i <= 'Z'; i++) {
			situation[i] = 0;
		}
		while (cin >> b && b != "#") {
			int L = (a.size() > b.size()) ? b.size() : a.size();
			for (int i = 0; i < L; ++i) {
				if (situation[a[i]] == 0) situation[a[i]] = 1;
				if (situation[b[i]] == 0) situation[b[i]] = 1;
				if (b[i] != a[i]) {
					graph.insert(pair<char, int>(a[i], b[i]));
					break;
				}
			}
			a = b;
		}
		for (char i = 'A'; i <= 'Z'; i++) {
			if (situation[i] == 1 && graph.find(i) != graph.end()) {
				situation[i] = 2;
				topological(graph, situation, ans, i);
			}
		}
		while (!ans.empty()) {
			cout << ans.top();
			ans.pop();
		}
		cout << endl;
	}
}
