#include <bits/stdc++.h>

using namespace std;

vector<int> runningSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> sums(n);

    sums[0] = nums[0];

    for (int i = 1; i < n; i++) {
        sums[i] = nums[i] + sums[i-1];
    }

    return sums;
}

int main() {
    vector<int> nums = {1, 2, 3, 4};

    vector<int> ans = runningSum(nums);

    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}