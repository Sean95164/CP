#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n, m;
    cin >> n >> m;
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi-m, t[i]);
        t[i] = maxi;
    }

    maxi = 0;
    for (int i = n-1; i >= 0; i--) {
        maxi = max(maxi-m, t[i]);
        t[i] = maxi;
    }
    
    for (int i = 0; i < n; i++) {
        cout << t[i] << " \n"[i==n-1];
    }
    return 0;
}