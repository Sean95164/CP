#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int cnt = 0;
	for (int k = 1; k <= 1000; k++) {
		int res = k * (k + 1) * (k + 2);
		
		if (res >= n) {
			break;
		}
		else {
			cnt++;
		}
	}
	
	cout << cnt << "\n";
	return 0;
}