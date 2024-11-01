#include <bits/stdc++.h>

using namespace std;

int main() {
	long long t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		long long ans = 0;
		
		// for i < sqrt(n)
		long long i = 1;
		for (; i*i < n; i++) {
			ans += n/i;
		}
		
		// for i >= sqrt(n)
		while(i <= n) {
			long long k = n / i;
			ans += ((n / k) - (n /(k+1))) * k;
			i = (n/k) + 1;
		}
		
		cout << ans << "\n";
	}
	return 0;
}