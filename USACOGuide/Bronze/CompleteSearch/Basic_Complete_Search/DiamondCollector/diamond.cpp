#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> sz(n);
    for (int i = 0; i < n; i++) {
        cin >> sz[i];
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (sz[i] <= sz[j] && sz[j] <= sz[i] + k) {
                cnt++;
            }
        }
        // cout << cnt << "\n";
        maxi = max(maxi, cnt);
    }
    cout << maxi << "\n";
    return 0;
}