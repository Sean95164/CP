#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int M = 20;

vector<vector<int>> table(N+1, vector<int>(M, 0));
vector<int> depth(N+1, -1);


void dfs(map<int,  vector<int>> tr, int cur, int par) {
    depth[cur] = depth[par] + 1;
    table[cur][0] = par;

    for (int j = 1; j < M; j++) {
        table[cur][j] = table[table[cur][j-1]][j-1];
    }

    for (auto x : tr[cur]) {   
        if (x != par) {
            dfs(tr, x, cur);
        }
    }
}

int query(int x, int y) {
    if (depth[x] < depth[y]) {
        swap(x, y);
    }

    int diff = depth[x] - depth[y];

    for (int j = M - 1; j >= 0; j--) {
        if ((diff >> j) & 1) {
            x = table[x][j];
        }
    }

    if (x == y) return x;


    // x and y are in same level now
    for (int j = M - 1; j >= 0; j--) {
        if (table[x][j] != table[y][j]) {
            x = table[x][j];
            y = table[y][j];
        }
    }

    return table[x][0];
}

vector<int> LCA(int n, vector<vector<int>>edges, vector<vector<int>>queries) {
    map<int,  vector<int>> tr;
    int x, y;
    for (auto p : edges) {
        x = p[0];
        y = p[1];
        tr[x].push_back(y);
        tr[y].push_back(x);
    }


    dfs(tr, 1, 0);

    // for (int i = 1; i <= n; i++) {
    //     cout << i << "--> ";
    //     for (int j = 0; j < 5; j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    vector<int> ans;
    for (auto p : queries) {
        x = p[0];
        y = p[1];
        ans.push_back(query(x, y));
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {3, 4},
        {3, 5}
    };
    vector<vector<int>> queries = {
        {4, 5},
        {2, 5},
        {1, 4}
    };

    vector<int> ans = LCA(n, edges, queries);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}