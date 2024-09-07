#include <bits/stdc++.h>

using namespace std;

bool checkArray(vector<int>& nums, int k) {
    int cur = 0, n = nums.size();
    for (int i = 0; i < n; i++) {
        if (cur > nums[i]) {
            return false;
        }

        nums[i] -= cur;
        cur += nums[i];

        if (i >= k - 1) {
            cur -= nums[i-k+1];
        }
    }

    return cur == 0;
    
}

int main() {
    vector<int> nums = {2,2,3,1,1,0};
    int k = 3;
    
    cout << checkArray(nums, k) << endl;
    return 0;
}