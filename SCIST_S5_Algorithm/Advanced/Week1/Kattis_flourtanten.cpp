#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int n;
	cin >> n;
	
	vector<int> arr(n+1);
	for (int i = 2; i <= n; i++) {
		cin >> arr[i];
		if (arr[i] == 0) {
			i--;
		}
	}
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * arr[i];
	}
	
	vector<int> pref(n+1, 0);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1] + arr[i];
	}
	
	int ans = sum;
	for (int i = 2; i <= n; i++) {
		int tmp = sum;

		tmp -= pref[i];
		ans = max(ans, tmp);
	}
	
	cout << ans << "\n";
	return 0;
}