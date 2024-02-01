#include <bits/stdc++.h>

using namespace std;

int countTriplets(vector<int> nums) {
    int n = nums.size();
    unordered_map<int, int> pairAND;

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		pairAND[nums[i] & nums[j]]++;
    	}
    }
    int ans = 0;
    for(const auto &pr:pairAND){
    	for(const int &num:nums){
    		if((pr.first & num) == 0){
    			ans += pr.second;
    		}
    	}
    }
    return ans;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> nums;
	int num;
	while(n--){
		cin >> num;
		nums.push_back(num);
	}

	cout << countTriplets(nums) << endl;
	
	
	return 0;
}