#include <bits/stdc++.h>

using namespace std;

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n;
	cin >> n;
	if(n&1)
		cout << "Odd";
	else 
		cout << "Even";

	cout << endl;

	return 0;
}