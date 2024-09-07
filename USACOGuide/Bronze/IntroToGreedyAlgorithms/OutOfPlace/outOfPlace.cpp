#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> h(n);

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> sorted(h);
    sort(sorted.begin(), sorted.end());

    int diff = 0;
    for (int i = 0; i < n; i++) {
        if (h[i] != sorted[i]) {
            diff++;
        }
    }

    cout << max(0, diff - 1) << endl;
    return 0;
}