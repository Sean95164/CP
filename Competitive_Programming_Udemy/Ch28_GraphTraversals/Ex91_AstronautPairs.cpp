#include <bits/stdc++.h>

using namespace std;

int dfs(map<int, vector<int>> graph, int i, vector<bool> &visited) {
    visited[i] = true;

    int ans = 1;
    for (auto nbr : graph[i]) {
        if (!visited[nbr]) {
            ans += dfs(graph, nbr, visited);
        }
    }

    return ans;
}

int count_pairs(int n, vector<pair<int,int> > astronauts){
    vector<int> count;
    map<int, vector<int>> graph;

    // build graph
    for (auto p : astronauts) {
        graph[p.first].push_back(p.second);
        graph[p.second].push_back(p.first);
    }

    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int c = dfs(graph, i, visited);
            count.push_back(c);
        }
    }

    long long sum = 0;
    for (int x : count) {
        sum += x;
    }

    long long ans = 0;
    for (int x : count) {
        sum -= x;
        ans += x * sum; 
    }

    return ans;
}

int main() {
    int n = 7;
    vector<pair<int, int> > astronauts = {
        {0, 1},
        {2, 3},
        {4, 5},
        {5, 6}
    };

    cout << count_pairs(n, astronauts) << "\n";
    return 0;
}