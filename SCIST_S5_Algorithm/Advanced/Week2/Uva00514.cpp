#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		
		vector<int> arr(n+1);
		while(true) {
			arr.clear();
			cin >> arr[1];
			if (arr[1] == 0) {
				break;
			}
			
			for (int i = 2; i <= n; i++) {
				cin >> arr[i];
			}
			
			stack<int> stk;
			
			int cur = 1;
			for (int i = 1; i <= n; i++) {
				if (!stk.empty() && arr[cur] == stk.top()) {
					stk.pop();
					i--;
					cur++;
				}
				else if (arr[cur] == i) {
					cur++;
				}
				else {
					stk.push(i);
				}
			}	
			
			bool ok = true;
			while(!stk.empty()) {
				if (stk.top() != arr[cur]) {
					ok = false;
					break;
				}
				else {
					stk.pop();
					cur++;
				}
			}
			
			if (ok) {
				cout << "Yes\n";	
			}
			else {
				cout << "No\n";
			}
			
		}
		
		
		cout << "\n";
	}
	
	return 0;
}