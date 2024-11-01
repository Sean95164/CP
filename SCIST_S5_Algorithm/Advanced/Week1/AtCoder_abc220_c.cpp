#include <bits/stdc++.h>

#define int long long
using namespace std;



int32_t main() {
	int n;
	cin >> n;
	
	int sum = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	
	int x;
	cin >> x;
	
	int k = 0;
	k += (x / sum) * n;
	int remaining = x % sum;
	
	int tmp = 0;
	int i = 0;
	while(tmp <= remaining) {
		tmp += arr[i % n];
		i++; 
		k++;
	}
	
	cout << k << "\n";
	return 0;
}