#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int n;
	cin >> n;
	
	int a, b, c;
	cin >> a >> b >> c;
	
	
	int mini = 10000;
	for (int i = 0; i <= 9999; i++) {
		for (int j = 0; j <= 9999; j++) {
			if (i + j >= 10000) {
				break;
			}
			
			int r = n - i * a - j * b;
			if (r < 0) {
				break;
			}
			if (r % c == 0) {
				mini = min(mini, i + j + (r / c));
			}
		}
	}
	
	cout << mini << "\n";
	return 0;
}