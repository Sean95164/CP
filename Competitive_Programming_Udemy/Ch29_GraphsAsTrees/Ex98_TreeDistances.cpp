#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

int bfs(map<int, vector<int>> tr, int src, int n) {
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, 0);
    queue<int> q;
    visited[src] = true;
    int top = src;
    q.push(src);
    while(!q.empty()) {
        int x = q.front();
        top = x;
        q.pop();
        for (auto ele : tr[x]) {
            if (!visited[ele]) {
                visited[ele] = true;
                dist[ele] = dist[x] + 1;
                q.push(ele);
                ans[ele] = max(ans[ele], dist[ele]);
            }
        }
    }

    return top;
}

vector<int> treeDistances(int n, vector<vector<int>>edges) {
    map<int, vector<int>> tr;
    ans.assign(n+1, -1);

    for (auto p : edges) {
        int x = p[0];
        int y = p[1];
        tr[x].push_back(y);
        tr[y].push_back(x);
    }

    int dist_end1 = bfs(tr, 1, n);
    int dist_end2 = bfs(tr, dist_end1, n);
    bfs(tr, dist_end2, n);

    vector<int> tmp;
    for (int i = 1; i <= n; i++) {
        tmp.push_back(ans[i]);
    }

    return tmp;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {3, 4},
        {3, 5}
    };
    vector<int> ans = treeDistances(n, edges);
    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}