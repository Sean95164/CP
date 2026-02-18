#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, q;
    cin >> n >> k >> q;
    
    int diff[MAXN];
    for (int i = 0; i < MAXN; i++) {
        diff[i] = 0;
    }
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        diff[l]++;
        diff[r+1]--;
    }

    for (int i = 1; i < MAXN; i++) {
        diff[i] += diff[i-1];
    }

    for (int i = 1; i < MAXN; i++) {
        diff[i] = (diff[i] >= k) + diff[i-1];
    }

    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << diff[r]-diff[l-1] << "\n";
    }
    return 0;
}