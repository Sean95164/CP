#include <bits/stdc++.h>

using namespace std;

const int ROOMS = 105;

int check(vector<int> rooms, vector<vector<int>> condi, int m, int mask) {
    int a, b, p, c;
    int cost = 0;
    for (int i = 0; i < m; i++) {
        if (mask & (1 << i)) {
            a = condi[i][0];
            b = condi[i][1];
            p = condi[i][2];
            c = condi[i][3];

            for (int j = a; j <= b; j++) {
                rooms[j] -= p;
            }

            cost += c;
        }
    }

    for (auto x : rooms) {
        if (x > 0) {
            return -1;
        }
    }

    return cost;
}

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> rooms(ROOMS, 0);

    int s, t, c;

    for (int i = 0; i < n; i++) {
        cin >> s >> t >> c;
        for (int j = s; j <= t; j++) {
            rooms[j] = max(rooms[j], c);
        }
    }

    vector<vector<int>> condi(m);

    int a, b, p, money;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> p >> money;
        condi[i] = {a, b, p ,money};
    }

    int ans = INT_MAX;
    int cost = -1;
    // enumerate all condition
    for (int mask = 0; mask < (1 << m); mask++) {
        cost = check(rooms, condi, m, mask);
        if (cost != -1) {
            ans = min(ans, cost);
        }
    }

    cout << ans << endl;
    return 0;
}