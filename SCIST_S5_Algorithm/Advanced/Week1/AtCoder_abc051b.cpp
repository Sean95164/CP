#include <bits/stdc++.h>

using namespace std;

int main() {
	int k, s;
	cin >> k >> s;
	
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k; j++) {
			if (i + j > s) {
				break;
			}
			
			int z = s - i - j;
			if (z <= k) {
				ans++;
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}