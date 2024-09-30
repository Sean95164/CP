#include <bits/stdc++.h>

using namespace std;

int n, m;
map<int, vector<int>> gr;
vector<bool> visited;

void dfs(int cur) {
    visited[cur] = true;
    for (auto nbr : gr[cur]) {
        if (!visited[nbr]) {
            dfs(nbr);
        }
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    

    cin >> n >> m;
    visited.resize(n+1, false);

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    
    vector<int> newRoads;

    int components = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            newRoads.push_back(i);
            components++;
            dfs(i);
        }
    }

    int start = newRoads[0];
    cout << components - 1 << "\n";
    for (int i = 1; i < (int)newRoads.size(); i++) {
        cout << start << " " << newRoads[i] << "\n";
    }


    return 0;
}