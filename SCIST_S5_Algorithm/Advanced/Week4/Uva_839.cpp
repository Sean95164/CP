#include <bits/stdc++.h>

using namespace std;

bool ok;

int check() {
	int wl, dl, wr, dr;
	cin >> wl >> dl >> wr >> dr;
	if (wl == 0) {
		wl = check();
	}
	
	if (wr == 0) {
		wr = check();
	}
	
	if (wl * dl != wr * dr) {
		ok = false;
	}
	
	return wl + wr;
}

int32_t main() {
	int t;
	cin >> t;
	while(t--) {
		ok = true;
		check();
		if (ok) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		
		if (t != 0) {
			cout << "\n";
		}
	}
	return 0;
}