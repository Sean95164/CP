#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int n, q;
    cin >> n >> q;

    vector<vector<char> > forest(n+1, vector<char>(n+1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> forest[i][j];
        }
    }

    vector<vector<int>> p(n+1, vector<int>(n+1, 0));

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            p[i][j] = p[i-1][j] + p[i][j-1] - p[i-1][j-1];
            if (forest[i][j] == '*') {
                p[i][j]++;
            }
        }
    }

    int a, b, c, d;

    for (int i = 0; i < q; i++) {
        cin >> a >> b >> c >> d;
        cout << p[c][d] - p[c][b-1] - p[a-1][d] + p[a-1][b-1] << endl;
    }
    return 0;
}