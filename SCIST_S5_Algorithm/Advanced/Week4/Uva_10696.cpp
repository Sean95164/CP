#include <bits/stdc++.h>

using namespace std;

int f(int n) {
	if (n <= 100) {
		int tmp = f(n+11);
		return f(tmp);
	}
	else {
		return n-10;
	}
}

int main() {
	
	vector<int> ans(101, 0);
	for (int i = 0; i <= 101; i++) {
		ans[i] = f(i);
	}
	
	int n;
	
	while(true) {
		cin >> n;
		if (n == 0) {
			break;
		}
		cout << "f91(" << n << ") = ";
		if (n <= 100) {
			cout << ans[n] << "\n";
		}
		else {
			cout << n - 10 << "\n";
		}
	}
	return 0;
}