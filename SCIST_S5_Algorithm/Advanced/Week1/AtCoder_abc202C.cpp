#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> a_num(n+1, 0);
	vector<int> b(n+1);
	vector<int> c(n+1);
	
	int num = 0;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		a_num[num]++;
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
	}
	
	long long count = 0;
	for (int cur : c) {
		count += a_num[b[cur]];
	}
	
	cout << count << "\n";
	return 0;
}