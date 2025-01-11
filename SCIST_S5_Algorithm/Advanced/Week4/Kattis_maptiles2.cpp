#include <bits/stdc++.h>

using namespace std;
#define int long long

int pow(int x, int y) {
	if (y == 0) {
		return 1;
	}
	
	int tmp = pow(x, y / 2);
	if (y % 2 == 0) {
		
		return tmp * tmp;
	}
	else {
		return tmp * tmp * x;
	}
}

void solve(string s, int &x, int &y, int n, int &index) {
	if (index == (int)s.size()) {
		return;
	}
	
	if (s[index] == '0') {
		// do nothing
	}
	else if (s[index] == '1') {
		x += n / 2;	
	}
	else if (s[index] == '2') {
		y += n / 2;
	}
	else {
		x += n / 2;
		y += n / 2;
	}
	
	index++;
	solve(s, x, y, n / 2, index);
}

int32_t main() {
	string s;
	cin >> s;
	int level = (int)s.size();
	
	int x = 0, y = 0;
	int index = 0;
	int n = pow(2, level);
	solve(s, x, y, n, index);
	
	cout << level << " " << x << " " << y << "\n";
	return 0;
}