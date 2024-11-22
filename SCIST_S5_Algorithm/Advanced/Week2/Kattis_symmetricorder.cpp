#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	
	int round = 1;
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		
		cout << "SET " << round << "\n";
		
		queue<string> q;
		stack<string> stk;
		string name;
		for (int i = 0; i < n; i++) {
			cin >> name;
			if (i % 2 == 0) {
				q.push(name);
			}
			else {
				stk.push(name);
			}
		}
		
		while(!q.empty()) {
			cout << q.front() << "\n";
			q.pop();
		}
		
		while(!stk.empty()) {
			cout << stk.top() << "\n";
			stk.pop();
		}
		
		round++;
	}
	
	
	return 0;
}