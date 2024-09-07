#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(n+1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i+1] = ((prefix[i] + arr[i]) % n + n) % n;
    }

    long long ans = 0;
    vector<int> cnt(n, 0);
    for (int i = 0; i < prefix.size(); i++) {
        ans += cnt[prefix[i]];
        cnt[prefix[i]]++;
    }

    cout << ans << endl;
    return 0;
}