#include <bits/stdc++.h>

using namespace std;

int search(vector<pair<int, int>> &arr, int l, int r, int target) {
    while(l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid].first == target) {
            return arr[mid].second;
        }
        else if (target < arr[mid].first) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return -1;
}

vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end());

    vector<int> ans;
    int x;
    for (int i = 0; i < n - 1; i++) {
        x = search(arr, i + 1, n - 1, target - arr[i].first);
        if (x != -1) {
            ans.push_back(arr[i].second);
            ans.push_back(x);
            break;
        }
    }
    
    return ans;
}

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> ans = twoSum(nums, target);
    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}