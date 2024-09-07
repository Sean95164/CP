#include<bits/stdc++.h>
using namespace std;

int MST(int n, vector<vector<int>> edges) {
    map<int, vector<pair<int, int>>> gr;
    int u, v, w;
    for (auto p : edges) {
        u = p[0];
        v = p[1];
        w = p[2];

        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    set<int> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    pq.push({0, 1});
    int ans = 0;

    int to, weight;
    while(visited.size() != n) {
        auto p = pq.top();
        pq.pop();

        weight = p.first;
        to = p.second;

        if (!visited.count(to)) {
            visited.insert(to);
            ans += weight;
            for (auto edge : gr[to]) {
                pq.push({edge.second, edge.first});
            }
        }
    }

    return ans;
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {1, 2, 7},
        {1, 4, 6},
        {4, 2, 9},
        {4, 3, 8},
        {2, 3, 6}
    };

    cout << MST(n, edges) << endl;
    return 0;
}