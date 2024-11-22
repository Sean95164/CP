#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	
	cin >> n;
	
	queue<int> child;
	for (int i = 1; i <= n; i++) {
		child.push(i);
	}
	
	queue<int> kill;
	
	int i = 0;
	while(!child.empty()) {
		
		// alive
		if (i % 2 == 0) {
			child.push(child.front());
			child.pop();
		}
		else {
			kill.push(child.front());
			child.pop();
		}
		i++;
	}
	
	for (int i = 0; i < n - 1; i++) {
		cout << kill.front() << " ";
		kill.pop();
	}
	cout << kill.front() << "\n";
	return 0;
}