#include <bits/stdc++.h>

using namespace std;

int main() {
	int a1, a2, a3;
	int b1, b2, b3;
	
	cin >> a1 >> a2 >> a3;
	cin >> b1 >> b2 >> b3;
	
	int n;
	cin >> n;
	
	int ans = INT_MIN;
	for (int x1 = 0; x1 <= n; x1++) {
		int x2 = n - x1;
		int y1 = a1 * x1 * x1 + a2 * x1 + a3;
		int y2 = b1 * x2 * x2 + b2 * x2 + b3;
		
		ans = max(ans, y1 + y2);
	}
	
	cout << ans << "\n";
	return 0;
}