#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	stack<int> first, second;
	
	int x;
	for (int i = 0; i < 2*n; i++) {
		cin >> x;
		second.push(x);
	}
	
	while(!second.empty()) {
		first.push(second.top());
		second.pop();
	}
	
	bool ok = true;
	int count = 0;
	
	while(true) {
		if (first.empty()) {
			break;
		}
		
		int cur = first.top();
		first.pop();
		
		if (!second.empty() && second.top() == cur) {
			second.pop();
		}
		else {
			second.push(cur);
		}
		
		
		
		count++;
	}
	
	if (!first.empty() || !second.empty()) {
		ok = false;
	}
	
	
	if (ok) {
		cout << count << "\n";
	}
	else {
		cout << "impossible\n";
	}
	return 0;
}