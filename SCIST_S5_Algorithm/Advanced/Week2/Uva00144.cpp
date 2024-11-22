#include <bits/stdc++.h>

using namespace std;

const int TOTAL = 40;

int main() {
	
	int n, k;
	while(cin >> n >> k) {
		if (n == 0 && k == 0) {
			break;
		}
		
		queue<int> q;
		vector<int> cash(n+1, 0);
		
		for (int i = 1; i <= n; i++) {
			q.push(i);
		}
		
		int next = 1;
		int remaining = 1;
		
		while(!q.empty()) {
			int student = q.front();
			q.pop();
			
			if (cash[student] + remaining >= TOTAL) {
				remaining -= TOTAL - cash[student];
				cash[student] = TOTAL;
				cout << setw(3) << student;
			}
			else {
				cash[student] += remaining;
				remaining = 0;
				q.push(student);
			}
			
			if (remaining == 0) {
				next++;
				if (next > k) {
					next -= k;
				}
				remaining = next;
			}
		}
		
		cout << "\n";
	}
	

	return 0;
}