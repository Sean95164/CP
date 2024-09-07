#include <bits/stdc++.h>

using namespace std;

int simulation(vector<bool> pos, vector<pair<int, int>> &changes, vector<int> &guess) {
    int total = 0;
    int n = changes.size();

    int a, b, g;
    for (int i = 0; i < n; i++) {
        a = changes[i].first;
        b = changes[i].second;
        g = guess[i];
        
        if (pos[a] || pos[b]) {
            swap(pos[a], pos[b]);
        }

        if (pos[g]) {
            total++;
        }

    }

    return total;
}

int main() {
    // freopen("shell.in", "r", stdin);
    // freopen("shell.out", "w", stdout);

    int n;
    cin >> n;

    vector<bool> pos(n+1, false);
    vector<pair<int, int>> change;
    vector<int> guess;

    int a, b, g;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> g;
        change.push_back({a,b});
        guess.push_back(g);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        pos[i] = true;
        ans = max(ans, simulation(pos, change, guess));
        pos[i] = false;
    }

    cout << ans << endl;
    return 0;
}