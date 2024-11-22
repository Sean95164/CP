#include <bits/stdc++.h>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
	double dx = x1 - x2;
	double dy = y1 - y2;
	
	return sqrt(dx*dx + dy*dy);
}

int main() {
	double gx, gy;
	cin >> gx >> gy;
	double dx, dy;
	cin >> dx >> dy;
	
	double hole_x, hole_y;
	cout << fixed << setprecision(3);
	while(cin >> hole_x >> hole_y) {
		if (2 * distance(gx, gy, hole_x, hole_y) <= distance(dx, dy, hole_x, hole_y)) {
			cout << "The gopher can escape through the hole at (";
			cout << hole_x << "," << hole_y << ").\n";
			return 0;
		}
	}
	
	
	cout << "The gopher cannot escape.\n";
	return 0;
}