#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> customers(n);
    vector<int> nums;
    

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        customers[i] = {a, b};
        nums.push_back(a);
        nums.push_back(b);
    }

    sort(nums.begin(), nums.end());
    map<int, int> mp;

    for (int i = 0; i < 2 * n; i++) {
        mp[nums[i]] = i;
    }

    vector<int> diff(2 * n + 1);
    for (auto &p : customers) {
        p.first = mp[p.first];
        p.second = mp[p.second];
        diff[p.first]++;
        diff[p.second + 1]--;
    }

    vector<int> times(2 * n);
    times[0] = diff[0];
    for (int i = 1; i < 2 * n; i++) {
        times[i] = diff[i] + times[i-1];
    }

    int ans = INT_MIN;
    for (int i = 0; i < 2*n; i++) {
        ans = max(ans, times[i]);
    }

    cout << ans << "\n";
    return 0;
}