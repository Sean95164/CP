#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> gr;
vector<int> groups;

int n, m;

bool check(int cur) {
    int group = groups[cur];
    for (auto nbr : gr[cur]) {
        if (groups[nbr] != -1 && groups[nbr] == group) {
            return false;
        }
    }

    return true;
}

bool dfs(int cur, int prev_group) {
    if (prev_group == 1) {
        groups[cur] = 2;
    }
    else {
        groups[cur] = 1;
    }

    if (!check(cur)) {
        return false;
    }

    for (auto nbr : gr[cur]) {
        if (groups[nbr] == -1) {
            if (!dfs(nbr, groups[cur])) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    
    cin >> n >> m;
    groups.resize(n+1, -1);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (groups[i] == -1) {
            if (!dfs(i, 2)) {
                cout << "IMPOSSIBLE" << "\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << groups[i] << " \n"[i==n];
    }
    return 0;
}