#include <bits/stdc++.h>

using namespace std;

bool checkRow(const vector<vector<int>> &arr, int r) {
	int n = arr.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[r][i];
	}
	
	return (sum % 2 == 0);
}

bool checkCol(const vector<vector<int>> &arr, int c) {
	int n = arr.size();
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i][c];
	}
	
	return (sum % 2 == 0);
}

int main() {
	int n;
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		
		vector<vector<int>> arr(n, vector<int>(n));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		bool ok = true;
		bool corrupt = false;
		
		int row = -1, col = -1;
		for (int i = 0; i < n ; i++) {
			if (!checkRow(arr, i)) {
				if (row != -1) {
					ok = false;
					corrupt = true;
					break;
				}
				else {
					row = i;
					ok = false;
				}
			}
			
			if (!checkCol(arr, i)) {
				if (col != -1) {
					ok = false;
					corrupt = true;
					break;
				}
				else {
					col = i;
					ok = false;
				}
			}
		}	
		
		
		if (ok) {
			cout << "OK\n";
		}
		else {
			if (corrupt) {
				cout << "Corrupt\n";
			}
			else {
				cout << "Change bit (" << row+1 << "," << col+1 << ")\n";
			}
		}
	}
	
	
	return 0;
}