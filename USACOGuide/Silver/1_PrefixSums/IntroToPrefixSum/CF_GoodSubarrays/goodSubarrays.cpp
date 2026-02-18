#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> psum(n+1);
        char c;
        for (int i = 1; i <= n; i++) {
            cin >> c;
            psum[i] = c-'0';
        }

        for (int i = 1; i <= n; i++) {
            psum[i] += psum[i-1];
        }

        // [l, r) : psum(r) - psum(l) = r - l
        //       -> psum(r) - r = psum(l) - l
        map<int, long long> cnt;
        for (int i = 0; i <= n; i++) {
            cnt[psum[i] - i]++;
        }
        long long ans = 0;
        for (const auto &[_, num] : cnt) {
            ans += num * (num-1) / 2;
        }

        cout << ans << "\n";
    }
    return 0;
}