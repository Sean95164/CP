#include <bits/stdc++.h>

using namespace std;

int UniqueNum1(vector<int> arr){
	int unique = 0;
	for(const int &num:arr){
		unique = unique ^ num;
	}

	return unique;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr = {1,2,3,4,5,9,5,3,4,2,1};
	
	int ans = UniqueNum1(arr);
	cout << ans << endl;

	return 0;
}