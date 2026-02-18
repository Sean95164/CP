#include <bits/stdc++.h>

using namespace std;

bool ok (const vector<int> &cows, int k, int m, int c) {
    int n = cows.size();
    int pos = 1;
    int lcow = 0;
    int needed_bus = 1;
    while(pos < n) {
        if (pos - lcow == c) {
            needed_bus++;
            lcow = pos;
        }
        else if (cows[pos] - cows[lcow] > k) {
            needed_bus++;
            lcow = pos;
        }
        
        pos++;
    }

    // cout << k << " " << needed_bus << "\n";
    return needed_bus <= m;
}

int main() {
    freopen("convention.in", "r", stdin);
    freopen("convention.out", "w", stdout);

    int n, m, c;
    cin >> n >> m >> c;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }
    
    
    
    sort(cows.begin(), cows.end());
    int l = 0, r = *max_element(cows.begin(), cows.end());
    while(l < r) {
        int mid = l + (r - l) / 2;
        if (ok(cows, mid, m, c)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }

    cout << l << "\n";
    return 0;
}