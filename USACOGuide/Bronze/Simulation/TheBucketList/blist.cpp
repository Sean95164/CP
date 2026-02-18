#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> t;
    int s, e, b;
    for (int i = 0; i < n; i++) {
        cin >> s >> e >> b;
        t.push_back({s, b});
        t.push_back({e, -b});
    }

    sort(t.begin(), t.end());
    int cur = 0;
    int ans = 0;
    for (int i = 0; i < (int) t.size(); i++) {
        cur += t[i].second;
        ans = max(ans, cur);
    }

    cout << ans << "\n";
    return 0;
}