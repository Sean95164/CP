#include <bits/stdc++.h>

using namespace std;

int messageRoute(int n, vector<vector<int>> edges){
    map<int, vector<int> > graph;

    for (auto p : edges) {
        int u = p[0];
        int v = p[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // bfs
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, 1);
    queue<int> q;

    visited[1] = true;
    q.push(1);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto nbr : graph[curr]) {
            if (!visited[nbr]) {
                dist[nbr] = dist[curr] + 1;
                visited[nbr] = true;
                q.push(nbr);
            }
        }
    }

    return dist[n] == 1 ? -1 : dist[n];
}

int main() {
    int n = 5;
    vector<vector<int>>edges = {
        {1, 2},
        {1, 3},
        {1, 4},
        {2, 3},
        {5, 4}
    };

    cout << messageRoute(n, edges) << "\n";
    return 0;
}