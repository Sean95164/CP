#include <bits/stdc++.h>

#define int long long
using namespace std;

int32_t main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	vector<vector<int>> b(h, vector<int>(w));
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> a[i][j];
		}
	}
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> b[i][j];
		}
	}
	
	int count = 0;
	for (int i = 0; i < h - 1; i++) {
		for (int j = 0; j < w - 1; j++) {
			if (a[i][j] != b[i][j]) {
				int diff = b[i][j] - a[i][j];
				a[i][j] += diff;
				a[i+1][j] += diff;
				a[i][j+1] += diff;
				a[i+1][j+1] += diff;
				count += abs(diff);
			}

		}
		
		if (a[i][w-1] != b[i][w-1]) {
			cout << "No" << "\n";
			return 0;
		}
	}
	
	for (int j = 0; j < w; j++) {
		if (a[h-1][j] != b[h-1][j]) {
			cout << "No" << "\n";
			return 0;
		}
	}
	
	
	cout << "Yes" << "\n";
	cout << count << "\n";
	return 0;
}