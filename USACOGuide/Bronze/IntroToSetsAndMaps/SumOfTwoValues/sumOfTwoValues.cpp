#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int n, x;
    cin >> n >> x;

    vector<int> arr(n+1);
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mp[arr[i]] = i;
    }

    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (mp.count(x - arr[i]) && i != mp[x - arr[i]]) {
            cout << i << " " << mp[x - arr[i]] << "\n";
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}