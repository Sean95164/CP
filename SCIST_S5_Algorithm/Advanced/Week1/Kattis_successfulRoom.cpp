#include <bits/stdc++.h>

using namespace std;

bool check(const vector<int> &arr, int k) {
	int size = arr.size();
	int prev = arr[k];
	for (int i = 2 * k; i < size; i += k) {
		int current = arr[i];
		if (current <= prev) {
			return false;
		}
		
		prev = current;
	}
	
	return true;
}

int main() {
	int n;
	cin >> n;
	
	vector<int> arr(n+1);
	
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	for (int k = 1; k <= n / 2; k++) {
		if (check(arr, k)) {
			cout << k << "\n";
			return 0;
		}
	}
	
	cout << "ABORT!" << "\n";
	return 0;
}