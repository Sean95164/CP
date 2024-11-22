#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		else if (n == 1) {
			cout << "Discarded cards:\n";;
			cout << "Remaining card: " << n << "\n";
			continue;
		}
		queue<int> q;
		vector<int> discarded;
		
		for (int i = 1; i <= n; i++) {
			q.push(i);
		}
		
		while(q.size() >= 2) {
			discarded.push_back(q.front());
			q.pop();
			
			q.push(q.front());
			q.pop();
		} 
		
		cout << "Discarded cards: ";
		

		int total = discarded.size();
		for (int i = 0; i < total - 1; i++) {
			cout << discarded[i] << ", ";
		}
		cout << discarded[total - 1] << "\n";


		
		if (!q.empty()) {
			cout << "Remaining card: " << q.front() << "\n";
		}
		
	}
	return 0;
}