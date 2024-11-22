#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	stack<int> condi;
	
	int cur = 0;
	condi.push(cur);
	string command;
	for (int i = 0; i < k; i++) {
		cin >> command;
		
		if (command == "undo") {
			int times;
			cin >> times;
			
			for (int i = 0; i < times; i++) {
				condi.pop();
			}
			cur = condi.top();
		}
		else {
			cur = (((stoi(command) % n) + (cur % n)) + n) % n;
			condi.push(cur);
		}
	}
	cout << cur << "\n";
	return 0;
}