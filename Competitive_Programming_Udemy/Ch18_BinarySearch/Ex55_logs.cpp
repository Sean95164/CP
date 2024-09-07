#include<bits/stdc++.h>
using namespace std;

bool check(int shortest, int n, int k, vector<int> logs) {
    int times = 0;
    for (auto x : logs) {
        times += (x - 1) / shortest;
    }

    if (times <= k) {
        return true;
    }
    else {
        return false;
    }
}

int solve(int n,int k, vector<int> a){
    int l = 1;
    int r = *max_element(a.begin(), a.end());

    int ans = -1;
    while(l <= r) {
        int mid = (l + r) / 2;
        if (check(mid, n, k, a)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n = 2;
    int k = 3;
    vector<int> a = {7, 9};
    cout << solve(n, k, a) << endl;
    return 0;
}