#include <bits/stdc++.h>

#define int long long
using namespace std;



int32_t main() {
	int n;
	cin >> n;
	
	vector<int> arr(n+1);
	vector<int> cnt(200, 0);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		cnt[arr[i] % 200]++;
	}
	
	int ans = 0;
	for (int i = 0; i < 200; i++) {
		ans += (cnt[i]*(cnt[i] - 1) / 2);
	}
	
	cout << ans << "\n";
	return 0;
}