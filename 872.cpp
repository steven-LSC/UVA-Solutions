#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

multimap<char,char> graph;
vector<char> ans;
map<char, int> situation;

bool backtracking(int length)
{
	if (length == situation.size()) {
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i)
			cout << ' ' << ans[i];
		cout << endl;
		return true;
	}

	bool hasAns = false;

	for (map<char, int>::iterator it = situation.begin(); it != situation.end(); it++) {
		if (it->second == 0) {
			//³]©w
			ans.push_back(it->first);   
			--it->second;         
			for (multimap<char, char>::iterator nxt = graph.lower_bound(it->first); nxt != graph.upper_bound(it->first); nxt++) {
				--situation[nxt->second]; 
			}

			//recursive
			hasAns = backtracking(length + 1);

			//´_­ì
			ans.pop_back();
			++it->second;
			for (multimap<char, char>::iterator nxt = graph.lower_bound(it->first); nxt != graph.upper_bound(it->first); nxt++) {
				++situation[nxt->second];
			}
		}
	}
	return hasAns;
}

int main()
{
	int cases;
	string temp_string;
	stringstream ss;
	char temp_char;
	cin >> cases;
	while (cases--) {
		ss.str("");
		ss.clear();
		graph.clear();
		ans.clear();
		situation.clear();
		while (getline(cin, temp_string) && temp_string.empty());
		ss << temp_string;
		while (ss >> temp_char)
		{
			situation[temp_char] = 0;
		}
		ss.str("");
		ss.clear();
		while (getline(cin, temp_string) && temp_string.empty());
		ss << temp_string;
		while (ss >> temp_string)
		{
			graph.insert(pair<char, char>(temp_string[0], temp_string[2]));
			situation[temp_string[2]]++;
		}

		if (!backtracking(0)) {
			cout << "NO" << endl;
		}
		if (cases) {
			cout << endl;
		}
	}
}