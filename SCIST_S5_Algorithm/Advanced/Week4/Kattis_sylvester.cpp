#include <bits/stdc++.h>

using namespace std;
#define ll long long

int find(ll n, ll r, ll c) {
	if (n == 1) {
		return 1;
	}
	ll mid = n / 2;
	// top-left
	if (r < mid && c < mid) {
		return find(n / 2, r, c);
	}
	// top-right
	else if (r < mid && c >= mid) {
		return find(n / 2, r, c - n / 2); 
	}
	// bottom-left
	else if (r >= mid && c < mid) {
		return find(n / 2, r - n / 2, c);
	}
	// bottom-right
	else {
		return -find(n / 2, r - n / 2, c - n / 2);
	}
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		ll n, x, y, w, h;
		cin >> n >> x >> y >> w >> h;
		for (ll i = y; i < y + h; i++) {
			for (ll j = x; j < x + w; j++) {
				if (j != x) {
					cout << " ";
				}
				cout << find(n, i, j);
			}
			cout << "\n";
		}
		cout << "\n";
	}
	
	
	return 0;
}