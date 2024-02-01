#include <bits/stdc++.h>

using namespace std;

bool isPowerOfFour(int n) {

	if(n<0) return false;
    // first check whether n is power of two
	// if it isn't the power of two, return false
	if( n & (n-1) != 0) return false;

	// 0x55555555 equals to 0b01010101010101010101010101010101
	return (n & 0x55555555) == n;   
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << boolalpha;
	cout << isPowerOfFour(n) << endl;
	
	return 0;
}