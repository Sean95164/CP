#include <bits/stdc++.h>

using namespace std;

int find_head(const vector<int> &front, int x) {
	while(front[x] != x) {
		x = front[x];
	}
	
	return x;
}



int main() {
	int n, q;
	cin >> n >> q;
	
	vector<int> rear(n+1);
	vector<int> front(n+1);
	
	for (int i = 1; i <= n; i++) {
		rear[i] = i;
		front[i] = i;
	}
	
	int t, x, y;
	for (int i = 0; i < q; i++) {
		cin >> t;
		if (t == 1) {
			cin >> x >> y;
			rear[x] = y;
			front[y] = x;
		} else if (t == 2) {
			cin >> x >> y;
			rear[x] = x;
			front[y] = y;
		} else {
			cin >> x;
			vector<int> print;
			int head = find_head(front, x);
			while(rear[head] != head) {
				print.push_back(head);
				head = rear[head];
			}
			
			print.push_back(head);
			int total = print.size();
			cout << total << " ";
			for (int i = 0; i < total; i++) {
				if (i == 0) {
					cout << print[i];
				}
				else {
					cout << " " << print[i];
				}
			}
			cout << "\n";
		}
	}
	return 0;
}