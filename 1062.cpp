#include<iostream>
#include<stack>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	string input;
	int temp = 1;
	while (cin >> input && input != "end") {
		vector<int> count;
		count.assign(input.size(), 1);
		int ans = 0;
		for (int i = 0; i < input.size(); i++) {
			for (int j = i + 1; j < input.size(); j++) {
				if (input[j] > input[i]) {
					count[j] = max(count[i] + 1, count[j]);
				}
			}
			ans = max(ans, count[i]);
		}
		cout << "Case " << temp << ": " << ans << endl;
		temp++;
	}
	return 0;
}