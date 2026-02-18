#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<pair<int, int>> a;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back({y, x});
    }
    sort(a.begin(), a.end());
    int i = 0, j = a.size()-1;
    int ans = 0;
    while(i <= j) {
        int sub = min(a[i].second, a[j].second);
        if (i == j) sub /= 2;
        ans = max(ans, a[i].first+a[j].first);
        a[i].second -= sub;
        a[j].second -= sub;
        if (a[i].second == 0) i++;
        if (a[j].second == 0) j--;
    }
    cout << ans << "\n";
    return 0;
}