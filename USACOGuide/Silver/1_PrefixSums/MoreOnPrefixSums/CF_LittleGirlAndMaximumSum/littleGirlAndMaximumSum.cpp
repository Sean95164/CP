#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> query_times(n+2);
    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        query_times[l]++;
        query_times[r+1]--;
    }

    vector<long long> nums(1);
    for (int i = 1; i < n+2; i++) {
        query_times[i] += query_times[i-1];
        if (i <= n) {
            nums.push_back(query_times[i]);
        }
    }
    sort(nums.begin(), nums.end());
    long long total = 0;
    for (int i = 1; i <= n; i++) {
        total += nums[i] * a[i];
    }

    cout << total << "\n";
    return 0;
}