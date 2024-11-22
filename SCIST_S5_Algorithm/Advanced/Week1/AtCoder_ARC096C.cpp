#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	
	long long money = 0;
	
	if (a + b >= 2 * c) {
		int num = min(x, y);
		money += 2 * c * num;
		x -= num;
		y -= num;
	}
	
	if (x > 0) {
		if (a < 2 * c) {
			money += a * x;
			x -= x;
		}
		else {
			money += c * 2 * x;
			x -= x;
			y -= x;
		}
	}
	
	if (y > 0) {
		if (b < 2 * c) {
			money += b * y;
			y -= y;
		}
		else {
			money += c * 2 * y;
			y -= y;
			x -= y;
		}
	}
	
	cout << money << "\n";
	return 0;
}