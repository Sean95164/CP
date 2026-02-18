#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1001;
int barn[MAXN][MAXN];

int main() {
    freopen("paintbarn.in", "r", stdin);
    freopen("paintbarn.out", "w", stdout);
    
    int n, k;
    cin >> n >> k;

    int x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        barn[x1][y1]++;
        barn[x2][y1]--;
        barn[x1][y2]--;
        barn[x2][y2]++;
    }

    int total = 0;
    for (int i = 0; i < MAXN; i++) {
        for (int j = 0; j < MAXN; j++) {
            if (i>0) barn[i][j] += barn[i-1][j];
            if (j>0) barn[i][j] += barn[i][j-1];
            if (i>0 && j>0) barn[i][j] -= barn[i-1][j-1];
            total += (barn[i][j] == k);
        }
    }

    cout << total << "\n";
    return 0;
}