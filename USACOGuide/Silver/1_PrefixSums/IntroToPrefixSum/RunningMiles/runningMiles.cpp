#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        vector<int> pref_max(n);
        vector<int> suff_max(n);

        for (int i = 0; i < n; i++) {
            pref_max[i] = arr[i] + i;
            suff_max[i] = arr[i] - i;
        }

        for (int i = 1; i < n; i++) {
            pref_max[i] = max(pref_max[i-1], pref_max[i]);
        }

        for (int i = n-2; i >= 0; i--) {
            suff_max[i] = max(suff_max[i], suff_max[i+1]);
        }

        int ans = 0;

        // iterate all m
        for (int i = 1; i < n-1; i++) {
            ans = max(ans, pref_max[i-1] + arr[i] + suff_max[i+1]);
        }

        cout << ans << endl;
    }
    
    return 0;
}