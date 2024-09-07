#include <bits/stdc++.h>

using namespace std;

bool ycmp(const pair<int, int> &p1, const pair<int, int> &p2) {
    return p1.second < p2.second;
}

int numOfCow(vector<vector<int>> &pre, int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x1-1][y2] - pre[x2][y1-1] + pre[x1-1][y1-1];
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<pair<int, int>> cows(n);

    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cows[i] = {x, y};
    }

    sort(cows.begin(), cows.end());
    for (int i = 0; i < n; i++) {
        cows[i].first = i + 1;
    }

    sort(cows.begin(), cows.end(), ycmp);
    for (int i = 0; i < n; i++) {
        cows[i].second = i + 1;
    }

    vector<vector<int>> pre(n+1, vector<int>(n+1, 0));

    for (int i = 0; i < n; i++) {
        pre[cows[i].first][cows[i].second] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pre[i][j] += pre[i][j-1] + pre[i-1][j] - pre[i-1][j-1];
        }
    }

    long long ans = 0;
    pair<int, int> cow1, cow2;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cow1 = cows[i];
            cow2 = cows[j];

            // x-axis is horizontal, y-axis is vertical
            int x1 = min(cow1.first, cow2.first);
            int x2 = max(cow1.first, cow2.first);
            ans += numOfCow(pre, 1, i+1, x1, j+1) * numOfCow(pre, x2, i+1, n, j+1);
        }
    }

    cout << ans + 1 << "\n";
    return 0;
}