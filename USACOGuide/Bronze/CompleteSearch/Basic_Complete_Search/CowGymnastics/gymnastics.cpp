#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int k, n;

    cin >> k >> n;
    vector<vector<int>> train;

    for (int i = 0; i < k; i++) {
        vector<int> tmp;

        int x;
        for (int j = 0; j < n; j++) {
            cin >> x;
            tmp.push_back(x);
        }

        train.push_back(tmp);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // cout << "(" << i << ", " << j << "): ";
            if (i == j) {
                continue;
            }

            bool ok = true;
            for (auto round : train) {
                int pos_i = -1, pos_j = -1;
                for (int k = 0; k < n; k++) {
                    if (round[k] == i) {
                        pos_i = k;
                    }
                    else if (round[k] == j) {
                        pos_j = k;
                    }
                }

                if (pos_i > pos_j) {
                    ok = false;
                    break;
                }
            }
            // cout << ok << endl;
            if (ok) {
                ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}