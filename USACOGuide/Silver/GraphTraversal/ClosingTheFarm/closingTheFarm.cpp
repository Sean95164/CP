#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> gr;


void dfs(int cur, vector<bool> &visited) {
    visited[cur] = true;
    for (auto nbr : gr[cur]) {
        if (!visited[nbr]) {
            dfs(nbr, visited);
        }
    }

}


int main() {
    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    vector<bool> state(n+1, false);
    int next_close = -1;
    
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(state);
        bool connected = true;

        for (int j = 1; j <= n; j++) {
            if (!state[j]) {
                dfs(j, visited);
                break;
            }
        }

        for (int j = 1; j <= n; j++) {
            if (!visited[j]) {
                connected = false;
                break;
            }
        }

        if (connected) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

        cin >> next_close;
        state[next_close] = true;
    }
    return 0;
}