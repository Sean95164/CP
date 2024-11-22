#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e5;

int sumOfDigits(int n) {
	int sum = 0;
	while(n != 0) {
		sum += n % 10;
		n /= 10;
	}
	
	return sum;
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> visited(mod, -1);
	vector<int> repeat;
	// a0 a1 a2 a3 a2 a3 a2 a3
	//  0  1  2  3  4  5  6  7
	int times = 0;
	int repeat_num = -1;
	while(visited[n] == -1) {
		// cout << "n: " << n << "\n";
		visited[n] = times;
		repeat.push_back(n);
		int y = sumOfDigits(n);
		n = (n + y) % mod;
		times++;
	}
	
	repeat_num = times - visited[n];
	
	k -= visited[n];
	cout << repeat[visited[n] + (k % repeat_num)] << "\n";
	return 0;
}