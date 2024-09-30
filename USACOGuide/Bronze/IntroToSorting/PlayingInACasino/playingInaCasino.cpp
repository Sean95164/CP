#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<long long>> nums(m, vector<long long>(n));

        int x;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> x;
                nums[j][i] = x;
            }
        }
        // sorting
        for (int i = 0; i < m; i++) {
            sort(nums[i].begin(), nums[i].end());
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += (2*j-n+1) * nums[i][j];
            }
        }

        cout << ans << "\n";
    }

    return 0;
}