#include <bits/stdc++.h>
#define int long long
using namespace std;

int power(int base, int exp) {
	if (exp == 0) {
		return 1;
	}
	int tmp = power(base, exp / 2);
	if (exp % 2 == 0) {
		return tmp * tmp;
	}
	else {
		return base * tmp * tmp;
	}
}

int32_t main() {
	int n;
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		bool neg = false;
		if (n < 0) {
			neg = true;
		}
		n = abs(n);
		int ans = 1;
		for (int p = 2; p <= 33; p++) {
			int b = 2;
			while(power(b, p) < n) {
				b++;
			}
			
			if (power(b, p) == n) {
				if (!neg || (neg && (p % 2 == 1))) {
					ans = p;
				}
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}