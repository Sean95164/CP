#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i].first >> time[i].second;
    }

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        vector<bool> covered(1001, false);
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int t = time[j].first; t < time[j].second; t++) {
                    covered[t] = true;
                }
            }   
        }
        int total = 0;
        for (int t = 0; t < 1001; t++) {
            total += covered[t];
        }
        maxi = max(maxi, total);
    }
    cout << maxi << "\n";
    return 0;
}