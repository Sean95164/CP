#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll power(ll a, ll b, ll c) {
	if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		ll tmp = power(a, b / 2, c) % c;
		return (tmp * tmp) % c;
	}
	else {
		ll tmp = power(a, b / 2, c) % c;
		return (((tmp * tmp) % c) * a) % c;
	}
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	
	cout << power(a, b, c) << "\n";
	return 0;
}