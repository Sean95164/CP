#include <bits/stdc++.h>

using namespace std;

vector<int> UniqueNum2(vector<int> arr){
	vector<int> ans;

	// XOR all numbers in the array
	int totalXOR = 0;
	for(const int &num:arr){
		totalXOR ^= num;
	}
	// using the total XOR number presenting the determination bits to filt numbers
	int unique1 = 0;
	for(const int &num:arr){
		if((totalXOR & num) == totalXOR){
			unique1 ^= num;
		}
	}

	// find unique number 1, and use it to XOR total to find unique number two
	int unique2 = totalXOR ^ unique1;

	ans.push_back(unique1);
	ans.push_back(unique2);

	return ans;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr = {1,3,5,4,3,1,5,7}; // 4 7

	vector<int> ans = UniqueNum2(arr);
	for(const int &num:ans){
		cout << num << " ";
	}

	cout << endl;
	return 0;
}