#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> sums(n+1);
    sums[0] = 0;

    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i-1] + arr[i-1];
    }

    int l, r;
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << sums[r] - sums[l] << endl;
    }
    return 0;
}