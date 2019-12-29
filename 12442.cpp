#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
vector<int> graph, sum;
vector<bool> visit;
int dfs(int u){
	if (visit[u]) {
		return 0;
	}
	visit[u] = true;
	int total = 1;
	if (visit[graph[u]] == false)
	{
		total = (1 + dfs(graph[u]));
		visit[graph[u]] = false;
	}
	return sum[u] = total;
}
int main(){
    int num_case;
    cin >> num_case;
	for (int cc = 1; cc <= num_case; cc++)
    {
		int num_edge;
		cin >> num_edge;
		graph.assign(num_edge + 1, -1);
		visit.assign(num_edge + 1, false);
		sum.assign(num_edge + 1, -1);
		for (int i = 0; i < num_edge; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a] = b;
		}
		int maxn = 0, ans = 0, tmp;
		for (int i = 1; i <= num_edge; i++)
		{
			tmp = 0;
			visit[i - 1] = false;
			if (sum[i] == -1) {
				tmp = dfs(i);
			}
			if (tmp > maxn){
				ans = i;
				maxn = tmp;
			}
		}
		cout << "Case " << cc << ": "<< ans << endl;
    }
	return 0;
}