#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int numberOfStation, truckCapacity, queueCapacity, firstNumber, temp, times = 0, move = 0;
		cin >> numberOfStation >> truckCapacity >> queueCapacity;
		vector<queue<int>> station;
		stack<int> truck;
		for (int i = 0; i < numberOfStation; i++) {
			cin >> firstNumber;
			queue<int> firstQueue;
			while (firstNumber--)
			{
				cin >> temp;
				firstQueue.push(temp);
			}
			station.push_back(firstQueue);
		}
		while (true) {
			//如果queue沒滿 1. 沒對應到，放queue 2.對應到放A
			//或是最上面是對應到的放A
			while (!truck.empty() && (station[move % numberOfStation].size() < queueCapacity || truck.top() == ((move % numberOfStation) + 1))) {
				if (truck.top() != ((move % numberOfStation) + 1)) {
					station[move % numberOfStation].push(truck.top());
					truck.pop();
					times++;
				}
				else {
					truck.pop();
					times++;
				}
			}
			//從B放入貨車
			while (truck.size() < truckCapacity && !station[move % numberOfStation].empty())
			{
				truck.push(station[move % numberOfStation].front());
				station[move % numberOfStation].pop();
				times++;
			}
			//是否結束
			bool check = true;
			for (int  i = 0; i < station.size(); i++)
			{
				if (!station[i].empty()) {
					check = false;
					break;
				}
			}
			if (check == true && truck.empty()) {
				cout << times << endl;
				break;
			}
			//沒結束，繼續
			times += 2;
			move++;
		}
	}
	return 0;
}