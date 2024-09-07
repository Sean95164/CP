#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int q;
    cin >> q;

    map<long long, long long> mp;

    long long t, k, v;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 0) {
            cin >> k >> v;
            mp[k] = v;
        }
        else if (t == 1) {
            cin >> k;
            cout << mp[k] << "\n";
        }
    }
    return 0;
}