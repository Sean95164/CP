#include<bits/stdc++.h>
using namespace std;

void topoSort(map<int, vector<int>> gr, int cur, set<int> &visited, vector<int> &order) {
    visited.insert(cur);
    for (auto nbr : gr[cur]) {
        if (!visited.count(nbr)) {
            
            topoSort(gr, nbr, visited, order);
        }
    }

    order.push_back(cur);
}

void dfs(map<int, vector<int>> gr, int cur, set<int> &visited) {
    visited.insert(cur);
    for (auto nbr : gr[cur]) {
        if (!visited.count(nbr)) {
            dfs(gr, nbr, visited);
        }
    }
}

bool solve(int n, vector<vector<int>> roads) {
    // using Kosaraju algorithm
    map<int, vector<int>> gr;
    map<int, vector<int>> reversedgr;

    int u, v;
    for (auto p : roads) {
        u = p[0];
        v = p[1];

        gr[u].push_back(v);
        reversedgr[v].push_back(u);
    }

    set<int> visited;
    vector<int> order;
    for (int i = 0; i < n; i++) {
        if (!visited.count(i)) {
            topoSort(gr, i, visited, order);
        }
    }

    reverse(order.begin(), order.end());
    visited.clear();

    dfs(reversedgr, order[0], visited);
    return visited.size() == n;
}

int main() {
    int n = 2;
    vector<vector<int>> roads = {
        {0, 1},
        {1, 0}
    };

    cout << solve(n, roads) << endl;
    return 0;
}