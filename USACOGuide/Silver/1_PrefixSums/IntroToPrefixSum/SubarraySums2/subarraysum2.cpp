#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    int n, x;
    cin >> n >> x;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefix(n+1,0);

    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + arr[i];
    }

    map<long long, int> count;

    long long ans = 0;
    for (int i = 0; i < prefix.size(); i++) {
        ans += count[prefix[i] - x];
        count[prefix[i]]++;
    }

    cout << ans << endl;
    return 0;
}