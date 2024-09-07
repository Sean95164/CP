#include<bits/stdc++.h>
using namespace std;

int intersect(vector<int> &nums, int s, int e) {
    // left: [s, mid], right: [mid+1, e];
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;
    int ptr = j;

    int cnt = 0;
    vector<int> tmp;
    // merge
    while(i <= mid) {
        while(ptr <= e && nums[i] > 2 * nums[ptr]) {
            ptr++;
        }
        cnt += (ptr - (mid + 1));
        // move to the first element in left bigger than right one
        while(j <= e && nums[i] >= nums[j]) {
            tmp.push_back(nums[j++]);
        }
        tmp.push_back(nums[i++]);
    }

    while(j <= e) {
        tmp.push_back(nums[j++]);
    }

    int k = 0;
    for (int idx = s; idx <= e; idx++) {
        nums[idx] = tmp[k++];
    }

    return cnt;
}

int solve(vector<int> &nums, int s, int e) {
    if (s >= e) {
        return 0;
    }

    int mid = (s + e) / 2;
    int c1 = solve(nums, s, mid);
    int c2 = solve(nums, mid+1, e);
    int intersec = intersect(nums, s, e);
    return c1 + c2 + intersec;
}

int reversePairs(vector<int> nums) {
    int e = nums.size() - 1;
    return solve(nums, 0, e);
}

int main() {
    vector<int> nums = {2, 4, 3, 5, 1};
    cout << reversePairs(nums) << endl;
    return 0;
}