#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<char>> signal(m, vector<char>(n));
    vector<string> ans;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> signal[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        string tmp;
        for (int j = 0; j < n; j++) {
            for (int t = 0; t < k; t++) {
                tmp.push_back(signal[i][j]);
            }
        }
        for (int t = 0; t < k; t++) {
            ans.push_back(tmp);
        }
    }
    
    for (const string &s : ans) {
        cout << s << "\n"; 
    }
    return 0;
}