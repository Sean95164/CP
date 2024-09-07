#include <bits/stdc++.h>

using namespace std;

void dfs(map<int, vector<int>> &gr, int cur, vector<bool> &visited) {
    visited[cur] = true;
    for (auto nbr : gr[cur]) {
        if (!visited[nbr]) {
            dfs(gr, nbr, visited);
        }
    }
}

bool check(map<int, vector<int>> &gr, int i, vector<bool> visited) {
    dfs(gr, i, visited);

    int k = 0;
    for (auto x : visited) {
        if (!x) {
            return false;
        }
        k++;
    }

    return true;
}

int main() {
    // freopen("factory.in", "r", stdin);
    // freopen("factory.out", "w", stdout);

    int n;
    cin >> n;

    map<int, vector<int>> gr;

    int x, y;
    for (int i = 0; i < n - 1; i++) {
        cin >> x >> y;
        x--;
        y--;
        gr[y].push_back(x);
    }

    vector<bool> visited(n, false);

    int ans = -1;
    for (int i = 0; i < n; i++) {
        if (check(gr, i, visited)) {
            ans = i + 1;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}