#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int l, int r, const int &value) {
    while(l <= r) {
        int mid = (l + r) / 2;
        if (value == nums[mid]) {
            return mid;
        }
        else if (value < nums[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1;
}

int arithmeticTriplets(vector<int>& nums, int diff) {
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int j = search(nums, i, n - 1, nums[i] + diff);
        if (j == -1) {
            continue;
        }

        int k = search(nums, j, n - 1, nums[j] + diff);
        if (k != -1) {
            ans++;
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {4,5,6,7,8,9};
    int diff = 2;
    cout << arithmeticTriplets(nums, diff) << endl;

    return 0;
}