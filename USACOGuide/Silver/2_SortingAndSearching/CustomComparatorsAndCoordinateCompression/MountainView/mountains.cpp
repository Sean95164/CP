#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    // 2 5 -> 3 4, 4 3, 5 2, 6 1
    // 4 6 -> 5 5, 6 4, 7 3, 8 2
    // 7 2 -> 8 1
    int n;
    cin >> n;
    vector<pair<int, int>> mountains(n); // (y, x)
    for (int i = 0; i < n; i++) {
        cin >> mountains[i].second >> mountains[i].first;
    }
    sort(mountains.rbegin(), mountains.rend());
    vector<bool> covered(n);
    for (int i = 0; i < n; i++) {
        if (!covered[i]) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int dx = abs(mountains[i].second - mountains[j].second);
                if (mountains[j].first <= mountains[i].first - dx) {
                    covered[j] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!covered[i]) {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}