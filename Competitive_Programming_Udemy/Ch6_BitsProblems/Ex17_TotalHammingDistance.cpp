#include <bits/stdc++.h>

using namespace std;

// solution1: less efficient
// int HammingDistance(int num1, int num2){
// 	int cnt = 0;
// 	int numXOR = num1 ^ num2;
// 	while(numXOR > 0){
// 		numXOR &= (numXOR - 1);
// 		cnt++;
// 	}
// 	return cnt;
// }

// int totalHammingDistance(vector<int> nums) {
//     int n = nums.size();
//     int ans = 0;
//     for(int i=0;i<n;i++){
//     	for(int j=i+1;j<n;j++){
//     		ans += HammingDistance(nums[i], nums[j]);
//     	}
//     }
//     return ans;
// }

// solution2: more efficient
int totalHammingDistance(vector<int> nums){
	/*
	For any bit position, the contribution to the total 
	Hamming distance is simply the number of 
	0s multiplied by the number of 1s.
	*/
	int n = nums.size();
	int dist = 0;
	
	for(int i=0;i<32;i++){
		int ones = 0;
		for(int j=0;j<n;j++){
			ones += (nums[j] & 1);
			nums[j]>>=1;
		}
		dist += ones * (n-ones);
	}

	return dist;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr;
	int n;
	cin >> n;
	int num;
	while(n--){
		cin >> num;
		arr.push_back(num);
	}

	cout << totalHammingDistance(arr) << endl;
	
	return 0;
}