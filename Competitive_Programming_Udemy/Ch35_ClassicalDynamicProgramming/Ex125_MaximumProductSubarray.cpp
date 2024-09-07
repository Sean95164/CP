#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> nums) {
    int n = nums.size();
    vector<int> maxDP(n);
    vector<int> minDP(n);

    int ans;
    ans = maxDP[0] = minDP[0] = nums[0];

    for (int i = 1; i < n; i++) {
        maxDP[i] = max(nums[i], max(nums[i]*maxDP[i-1], nums[i]*minDP[i-1]));
        minDP[i] = min(nums[i], min(nums[i]*maxDP[i-1], nums[i]*minDP[i-1]));
        ans = max(ans, max(maxDP[i], minDP[i]));
    }

    return ans;
}

int main() {
    cout << maxProduct({2, 3, -2, 4}) << endl;
    return 0;
}