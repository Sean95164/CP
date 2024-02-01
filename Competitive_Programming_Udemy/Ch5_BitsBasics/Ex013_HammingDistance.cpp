#include <bits/stdc++.h>

using namespace std;

int hammingDistance(int x, int y) {
    // Do XOR to seperate the diffrence to 1
	int num = (x ^ y);
	
    // Count the numbers of one
    int ones = 0;

    while(num > 0){
    	num = num & (num - 1);
    	ones++;
    }

    return ones;
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int x, y;
	cin >> x >> y;

	cout << hammingDistance(x, y) << endl;
	
	return 0;
}