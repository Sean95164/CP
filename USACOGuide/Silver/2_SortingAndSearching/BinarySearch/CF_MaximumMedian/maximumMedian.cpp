#include <bits/stdc++.h>

using namespace std;

bool ok(int n, const vector<int> &nums, long long median, int k) {
    long long total = 0;
    if (nums[n/2] >= median) return true;
    for (int i = n/2; i < n && nums[i] < median; i++) {
        total += median - nums[i];
    }

    return total <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    long long left = 0, right = 1e10;
    while(left < right) {
        long long mid = left + (right - left) / 2;
        if (ok(n, nums, mid, k)) {
            left = mid+1;
        }
        else {
            right = mid;
        }
    }

    cout << left - 1 << "\n";
    return 0;
}