#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> arr(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	
	vector<long long> prefix(n+1, 0);
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i-1] + arr[i];
	}
	
	long long left = 0;
	long long right = 0;
	long long ans = 0;
	
	for (int k = 1; k <= n; k++) {
		left += arr[k] * arr[k];
		right = prefix[n] - prefix[k];
		
		ans = max(ans, left * right);
	}
	
	cout << ans << "\n";
	return 0;
}