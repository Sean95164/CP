#include <bits/stdc++.h>

using namespace std;

long long distance(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    return dx*dx + dy*dy;
}

int main() {
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    long long ans = LLONG_MIN;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            ans = max(ans, distance(x[i], y[i], x[j], y[j]));
        }
    }

    cout << ans << endl;
    return 0;
}