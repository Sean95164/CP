#include <bits/stdc++.h>

using namespace std;

int result(int x, int y, int type, bool &ok) {
	if (type == 0) {
		return x + y;
	}
	else if (type == 1) {
		return x - y;
	}
	else if (type == 2) {
		return x * y;
	}
	else {
		if (x % y != 0) {
			ok = false;
			return INT_MIN;
		}
		else {
			return x / y;
		}
	}
}

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	const int TYPES = 4;

	int ans = INT_MAX;
	for (int i = 0; i < TYPES; i++) {
		for (int j = 0; j < TYPES; j++) {
			bool ok = true;
			int tmp = result(a, b, i, ok);
			int tmp2 = result(tmp, c, j, ok);
			
			if (!ok || tmp2 < 0) {
				// do not compare with answer
			}
			else {
				ans = min(ans, tmp2);
			}
		}
	}
	
	cout << ans << "\n";
	return 0;
}












