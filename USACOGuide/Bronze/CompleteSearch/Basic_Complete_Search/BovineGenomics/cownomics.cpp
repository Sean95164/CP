#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<string> spot(n);
    vector<string> plain(n);
    for (int i = 0; i < n; i++) {
        cin >> spot[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> plain[i];
    }

    int total = 0;
    for (int pos = 0; pos < m; pos++) {
        bool potential = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (spot[i][pos] == plain[j][pos]) {
                    potential = false;
                }
            }
        }
        if (potential) {
            total++;
        }
    }
    cout << total << "\n";
    return 0;
}