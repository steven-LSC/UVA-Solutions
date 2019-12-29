#include<iostream>
#include<algorithm>
#include<sstream>
#include<vector>
#include<string>
#include<map>
using namespace std;
map<char, bool> candel;
map<char, vector<char>> graph;
int put;
int DFS(char m_position, char t_position, int step) {
	candel[m_position] = (!((++step) % put));
	for (int i = 0; i < graph[m_position].size(); i++) {
		if (!candel[graph[m_position][i]] && graph[m_position][i] != t_position) {
			if (candel[m_position]) {
				cout << m_position << " ";
			}
			return DFS(graph[m_position][i], m_position, step);
		}
	}
	cout << "/" << m_position << endl;
	return 0;
}
int main() {
	string input;
	while (getline(cin, input) && input != "#")
	{
		candel.clear();
		graph.clear();
		string temp;
		int guide, x;
		char mPosition, tPosition;
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == ':') {
				guide = i - 1;
				for (int y = i + 1; y < input.size(); y++) {
					if (input[y] != ';' && input[y] != '.') {
						graph[input[guide]].push_back(input[y]);
					}
					else {
						break;
					}
				}
			}
			if (input[i] == '.') {
				i += 2;
				mPosition = input[i];
				i += 2;
				tPosition = input[i];
				i += 2;
				for (int x = i; x < input.size(); x++) {
					temp += input[x];
				}
				stringstream geek(temp);
				geek >> put;
				break;
			}
		}
		DFS(mPosition, tPosition, 0);
	}
	return 0;
}