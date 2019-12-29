#include <iostream>
#include <string>
#include <queue>
#include<map>
#include<vector>
using namespace std;

int main() {
	int cases, ferryCapacity, crossTime, numberOfCar, temp;
	cin >> cases;
	while (cases--) {

		cin >> ferryCapacity >> crossTime >> numberOfCar;

		bool position = 0;
		vector<queue<int>> port;
		queue<int> leftport;
		queue<int> rightport;
		port.push_back(leftport);
		port.push_back(rightport);
		
		queue<pair<int, bool>> information;
		queue<int> ferry;
		//裝完->刪掉->對面
		for (int i = 0; i < numberOfCar; i++) {
			string stemp;
			cin >> temp >> stemp;
			pair<int, bool> pTemp(temp, stemp == "right");
			information.push(pTemp);
		}
		int time = 0, number = 0;
		multimap<int, int> dictionary;
		while (true)
		{
			//全空就結束
			if (information.empty() && port[0].empty() && port[1].empty() && ferry.empty()) {
				break;
			}
			//船跟兩個港口都是空的
			if (ferry.empty() && port[0].empty() && port[1].empty()) {
				//處理到 下一步是送到目的地
				if (information.front().second == position) {
					time = information.front().first;
					port[position].push(number++);
					information.pop();
				}
				else {
					time = information.front().first;
					time += crossTime;
					position = !position;
					port[position].push(number++);
					information.pop();
				}
			}
			//船跟兩個港口只要有一個沒空就運作
			else {
				//先放車
				while (!ferry.empty())
				{
					dictionary.insert(pair<int, int>(ferry.front(), time));//車子不會隨著編號下船 因此map可以幫忙按照
					ferry.pop();										   //編號排好，並記錄那個編號下船的時間點
				}
				//車放到船上
				for (int i = 0; i < ferryCapacity; i++)
				{
					if (!port[position].empty()) {
						ferry.push(port[position].front());
						port[position].pop();	
					}
					else {
						break;
					}
				}
				//有可能車放下後 港口沒車 那就不要動 放下後其中一個有車那就往另一邊走
				if (!ferry.empty() || !port[0].empty() || !port[1].empty()) {
					position = !position;
					time += crossTime;
				}
			}
			//每跨一次河 都要確認是否時間已經到了要加入新的車子
			while (!information.empty() && time >= information.front().first) {
				port[information.front().second].push(number++);
				information.pop();
			}
		}
		for (multimap<int, int>::iterator it = dictionary.begin(); it != dictionary.end(); it++) {
			cout << it->second << endl;
		}
		if (cases != 0) {
			cout << endl;
		}
	}
	return 0;
}