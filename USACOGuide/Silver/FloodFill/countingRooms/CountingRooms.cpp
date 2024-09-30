#include <bits/stdc++.h>

using namespace std;

const int N = 1005;
vector<string> mp(N);
vector<vector<bool>> visited(N, vector<bool>(N, false));
int n, m;

void floodfill(int row, int col) {
    if (row < 0 || row >= n || col < 0 || col >= m || visited[row][col] || mp[row][col] == '#') {
        return;
    }

    visited[row][col] = true;
    floodfill(row-1, col);
    floodfill(row+1, col);
    floodfill(row, col-1);
    floodfill(row, col+1);
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    
    cin >> n >> m;

    string row;
    for (int i = 0; i < n; i++) {
        cin >> row;
        mp[i] = row;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mp[i][j] == '#' || visited[i][j]) continue;
            ans++;

            floodfill(i, j);
        }
    }

    cout << ans << "\n";
    return 0;
}