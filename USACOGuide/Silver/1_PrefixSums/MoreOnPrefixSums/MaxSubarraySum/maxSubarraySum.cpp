#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(n+1);
    partial_sum(arr.begin(), arr.end(), prefix.begin()+1);

    vector<long long> mini(n);
    mini[0] = prefix[0];
    for (int i = 1; i < n; i++) {
        mini[i] = min(mini[i-1], prefix[i]);
    }

    long long ans = LONG_LONG_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, prefix[i+1] - mini[i]);
    }

    cout << ans << endl;
    return 0;
}