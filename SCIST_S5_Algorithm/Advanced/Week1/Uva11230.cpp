#include <bits/stdc++.h>
#define int long long
using namespace std;

void flip(vector<vector<char>> &cur, int sr, int sc, int r, int c) {
	for (int i = sr; i < sr + r; i++) {
		for (int j = sc; j < sc + c; j++) {
			if (cur[i][j] == '0') {
				cur[i][j] = '1';
			}
			else {
				cur[i][j] = '0';
			}
			
		}
	}
}

void print(const vector<vector<char>> &cur) {
	for (auto row : cur) {
		for (char col : row) {
			cout << col << " ";
		}
		
		cout << "\n";
	}
}

int32_t main() {
	int n, m, r, c;
	
	while(cin >> n >> m >> r >> c) {
		if (n == 0 && m == 0 && r == 0 && c == 0) {
			break;
		}
		
		vector<vector<char>> cur(n, vector<char>(m, '0'));
		vector<vector<char>> target(n, vector<char>(m));
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> target[i][j];
			}
		}
		
		int count = 0;
		for (int i = 0; i < n - r + 1; i++) {
			for (int j = 0; j < m - c + 1; j++) {
				if (cur[i][j] != target[i][j]) {
					flip(cur, i, j, r, c);
					count++;
				}
			}
		}
		
		// print(cur);
		bool ok = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (cur[i][j] != target[i][j]) {
					cout << -1 << "\n";
					ok = false;
					break;
				}
			}
			if (!ok) {
				break;
			}
		}
		
		if (ok) {
			cout << count << "\n";
		}
	}
	return 0;
}