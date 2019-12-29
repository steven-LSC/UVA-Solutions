#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int cases, a, b;
	while (cin >> cases) {
		queue<int> my_queue;
		stack<int> my_stack;
		priority_queue<int> my_pqueue;
		bool is_stack = true, is_queue = true, is_pqueue = true;

		for (int i = 0; i < cases; i++) {
			cin >> a >> b;

			switch (a) {
			case 1:
				if (is_stack)
					my_stack.push(b);
				if (is_queue)
					my_queue.push(b);
				if (is_pqueue)
					my_pqueue.push(b);
				break;
			case 2:
				if (is_stack) {
					if (my_stack.empty() || my_stack.top() != b)
						is_stack = false;
					else
						my_stack.pop();
				}
				if (is_queue) {
					if (my_queue.empty() || my_queue.front() != b)
						is_queue = false;
					else
						my_queue.pop();
				}
				if (is_pqueue) {
					if (my_pqueue.empty() || my_pqueue.top() != b)
						is_pqueue = false;
					else
						my_pqueue.pop();
				}
				break;
			}
		}

		if (is_stack == true && is_queue == false && is_pqueue == false)
			cout << "stack" << endl;
		else if (is_stack == false && is_queue == true && is_pqueue == false)
			cout << "queue" << endl;
		else if (is_stack == false && is_queue == false && is_pqueue == true)
			cout << "priority queue" << endl;
		else if (is_stack == false && is_queue == false && is_pqueue == false)
			cout << "impossible" << endl;
		else
			cout << "not sure" << endl;
	}
}