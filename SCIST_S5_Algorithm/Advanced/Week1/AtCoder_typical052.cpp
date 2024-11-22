#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int32_t main() {
	int n;
	cin >> n;
	
	vector<vector<int>> dies(n, vector<int>(6));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> dies[i][j];
		}
	}
	
	int right = 1;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < 6; j++) {
			sum += dies[i][j];
		}
		
		right = (right * sum) % mod;
	}
	
	cout << right << "\n";
	return 0;
}