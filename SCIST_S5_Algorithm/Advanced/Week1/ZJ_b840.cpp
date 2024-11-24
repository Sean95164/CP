#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<int>> arr) {
	for (auto row : arr) {
		for (auto col : row) {
			cout << col << " ";
		}
		cout << "\n";
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> arr(n+1, vector<int>(n+1, 0));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	vector<vector<int>> prefix(n+1, vector<int>(n+1, 0));
	for (int i = 1; i <= n; i++) {
		prefix[i][1] = prefix[i-1][1] + arr[i][1];
		prefix[1][i] = prefix[1][i-1] + arr[1][i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= n; j++) {
			prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] + arr[i][j] - prefix[i-1][j-1];
		}
	}
	
	int ans = 0;
	for (int a = 1; a <= n; a++) {
		for (int b = 1; b <= n; b++) {
			for (int c = a; c <= n; c++) {
				for (int d = b; d <= n; d++) {
					int current = prefix[c][d] - prefix[c][b-1] - prefix[a-1][d] + prefix[a-1][b-1];
					ans = max(ans, current);
				}
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}