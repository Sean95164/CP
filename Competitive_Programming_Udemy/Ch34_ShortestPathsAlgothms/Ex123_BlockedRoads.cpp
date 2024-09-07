#include<bits/stdc++.h>
using namespace std;

int BFS(map<int, vector<int>> gr, int src, int des, int u, int v) {
    int n = des;
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;

    queue<int> q;
    q.push(1);
    vector<bool> visited(n + 1, false);
    visited[1] = true;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto x : gr[cur]) {
            if (cur == u && x == v) continue;

            if (!visited[x]) {
                visited[x] = true;
                dist[x] = dist[cur] + 1;
                q.push(x);
            }

        }
    }

    return dist[des];
}

vector<int> solve(int n,int m, vector<vector<int>> edge) {
    map<int, vector<int>> gr;
    int u, v;
    for (auto p : edge) {
        u = p[0];
        v = p[1];
        gr[u].push_back(v);
    }

    vector<int> ans;
    for (int i = 0; i < m; i++) {
        u = edge[i][0];
        v = edge[i][1];
        int res = BFS(gr, 1, n, u, v);
        if (res == INT_MAX) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(res);
        }
        
    }

    return ans;
}

int main() {
    int n = 4;
    int m = 4;
    vector<vector<int>> edge = {
        {1, 2},
        {2, 3},
        {2, 4},
        {3, 4}
    };

    vector<int> ans = solve(n, m, edge);
    
    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}