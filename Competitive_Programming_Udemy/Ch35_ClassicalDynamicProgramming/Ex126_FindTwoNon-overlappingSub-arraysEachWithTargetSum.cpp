#include<bits/stdc++.h>
using namespace std;

int minSumOfLengths(vector<int> arr, int target) {
    int n = arr.size();
    vector<int> dp(n, INT_MAX);

    int ans = INT_MAX, len = INT_MAX;
    int l = 0, r = 0, sum = 0;

    while(r < n) {
        sum += arr[r];

        while(sum > target) {
            sum -= arr[l++];
        }

        if (sum == target) {
            if (l != 0 && dp[l - 1] != INT_MAX) {
                ans = min(ans, dp[l-1] + r - l + 1);
            }
            len = min(len, r - l + 1);
        }

        dp[r] = len;
        r++;
    }

    return ans == INT_MAX ? -1 : ans;
}

int main() {
    cout << minSumOfLengths({1, 1, 1, 3, 5, 1, 2, 1}, 3) << endl;
    return 0;
}