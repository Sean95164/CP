#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	stack<char> stk;
	
	bool ok = true;
	for (int i = 0; i < n; i++) {
		char cur = s[i];
		if (cur == '(' || cur == '[' || cur == '{') {
			stk.push(cur);
		}
		else {
			if (stk.empty()) {
				ok = false;
				break;
			}
			
			char top = stk.top();
			if ((top == '(' && cur == ')') ||
				(top == '[' && cur == ']') ||
				(top == '{' && cur == '}')) {
					stk.pop();
				}
			else {
				ok = false;
				break;
			}
		}
	}
	
	if (!stk.empty()) {
		ok = false;
	}
	
	if (ok) {
		cout << "Valid\n";
	}
	else {
		cout << "Invalid\n";
	}
	return 0;
}