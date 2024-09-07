#include<bits/stdc++.h>
using namespace std;

int __findTargetSumWays(vector<int> nums, int target, int n, int index) {
    if (index == n) {
        if (target == 0) {
            return 1;
        }
        return 0;
    }

    return __findTargetSumWays(nums, target - nums[index], n, index + 1) +
        __findTargetSumWays(nums, target + nums[index], n, index + 1);
}

int findTargetSumWays(vector<int> nums, int target) {
    int n = nums.size();
    return __findTargetSumWays(nums, target, n, 0);
}

int main() {
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << findTargetSumWays(nums, target) << endl;

    return 0;
}