#include <bits/stdc++.h>

using namespace std;

int findKthLargest(vector<int> nums, int k) {
 	sort(nums.begin(), nums.end(), greater<int>());
 	for(const int &num:nums){
 		if(k == 1) return num;
 		k--;
 	}
 	return -1;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> vec;
	int n, num;
	cin >> n;
	while(n--){
		cin >> num;
		vec.push_back(num);
	}

	int k;
	cin >> k;
	cout << findKthLargest(vec, k) << endl;
	
	return 0;
}