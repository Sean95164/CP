#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<pair<int, int>> op_range(m+1);
    vector<long long> op_value(m+1);
    for (int i = 1; i <= m; i++) {
        cin >> op_range[i].first >> op_range[i].second >> op_value[i];
    }
    vector<long long> s(m+2);
    vector<long long> add(n+2);
    int l, r;
    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        s[l]++;
        s[r+1]--;
    }
    for (int i = 1; i <= m; i++) {
        s[i] += s[i-1];
        // cout << i << "th op nums: " << s[i] << "\n";
        add[op_range[i].first] += op_value[i] * s[i];
        add[op_range[i].second + 1] -= op_value[i] * s[i];
    }

    for (int i = 1; i <= n; i++) {
        add[i] += add[i-1];
        a[i] += add[i];
        cout << a[i] << " \n"[i==n];
    }
    return 0;
}