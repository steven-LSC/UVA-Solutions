#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<vector<bool>> grid;
vector<vector<bool>> visited;

void dfs(int x, int y, vector<int>& dx, vector<int>& dy, int R, int C, int& even, int& odd) {
	if (visited[x][y]) {
		return;
	}
	visited[x][y] = true;
	int cnt = 0;
	set<pair<int, int>> see;
	for (int i = 0; i < 4; i++) {
		if (x + dx[i] < R && x + dx[i] >= 0 && y + dy[i] < C &&
			y + dy[i] >= 0 && !grid[x + dx[i]][y + dy[i]]) {
			if (see.count(pair<int, int>(x + dx[i], y + dy[i])) == 0) {
				cnt++;
				see.insert(pair<int, int>(x + dx[i], y + dy[i]));
			}
			dfs(x + dx[i], y + dy[i], dx, dy, R, C, even, odd);
		}
	}
	for (int i = 0; i < 4; i++) {
		if (x + dy[i] < R && x + dy[i] >= 0 && y + dx[i] < C &&
			y + dx[i] >= 0 && !grid[x + dy[i]][y + dx[i]]) {
			if (see.count(pair<int, int>(x + dy[i], y + dx[i])) == 0) {
				cnt++;
				see.insert(pair<int, int>(x + dy[i], y + dx[i]));
			}
			dfs(x + dy[i], y + dx[i], dy, dx, R, C, even, odd);
		}
	}
	cnt % 2 ? odd++ : even++;
}

int main() {
	int num_case;
	cin >> num_case;
	for (int t = 1; t <= num_case; t++) {
		int R, C, M, N, num_grid, x, y;
		cin >> R >> C >> M >> N;

		grid.clear();
		visited.clear();
		grid.assign(R, vector<bool>(C));
		visited.assign(R, vector<bool>(C));
		
		vector<int> dx = { 1, 1, -1, -1 }, dy = { 1, -1, 1, -1 };
		for (int i = 0; i < 4; i++) {
			dx[i] *= M, dy[i] *= N;
		}

		cin >> num_grid;
		for (int i = 0; i < num_grid; i++) {
			cin >> x >> y;
			grid[x][y] = true;
		}

		int even = 0, odd = 0;
		dfs(0, 0, dx, dy, R, C, even, odd);
		cout << "Case " << t << ": " << even << ' ' << odd << endl;
	}
}