#include <bits/stdc++.h>

using namespace std;

int rangeBitwiseAnd(int left, int right) {

	// find the largest common prefix in binary notation
	int ans = 0;
	for(int i=31;i>=0;i--){
		int mask = (1<<i);
		int bitL = (left & mask) > 0, bitR = (right & mask) > 0;

		if(bitL == bitR){
			ans += bitL * mask;
		}
		else
			return ans;
	}

	return ans;
	
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	
	int left, right;
	cin >> left >> right;

	cout << rangeBitwiseAnd(left, right) << endl;
	return 0;
}