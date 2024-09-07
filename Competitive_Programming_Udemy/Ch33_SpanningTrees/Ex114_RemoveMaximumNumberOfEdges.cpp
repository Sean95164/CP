#include<bits/stdc++.h>
using namespace std;

bool MST(int n, map<int, vector<pair<int, int>> > gr, set<vector<int>> &usedEdges) {
    set<int> visited;
    priority_queue<pair<int, int>> pq;

    int prev = 0;
    pq.push({-1, 1});

    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        int type = it.first;
        int num = it.second;
        
        // go to num (Choose it!)
        if (!visited.count(num)) {
            usedEdges.insert({type, prev, num});
            usedEdges.insert({type, num, prev});
            visited.insert(num);
            prev = num;
            for (auto nbrPair : gr[num]) {
                int t = nbrPair.first;
                int nbr = nbrPair.second;

                if (!visited.count(nbr)) {
                    pq.push({t, nbr});
                }
            } 
        }
    }

    return visited.size() == n;
}

int maxNumEdgesToRemove(int n, vector<vector<int>> edges) {
    map<int, vector<pair<int, int>> > gr1;
    map<int, vector<pair<int, int>> > gr2;

    int t, u, v;
    for (auto edge : edges) {
        t = edge[0];
        u = edge[1];
        v = edge[2];

        if (t == 1) {
            gr1[u].push_back({t, v});
            gr1[v].push_back({t, u});
        }
        else if (t == 2) {
            gr2[u].push_back({t, v});
            gr2[v].push_back({t, u});
        }
        else {
            gr1[u].push_back({t, v});
            gr1[v].push_back({t, u});
            gr2[u].push_back({t, v});
            gr2[v].push_back({t, u});
        }
    }

    set<vector<int>> usedEdges;

    if (!MST(n, gr1, usedEdges) || !MST(n, gr2, usedEdges)) {
        return -1;
    }

    return edges.size() - ((usedEdges.size() - 2) / 2);
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {
        {3,1,2},{3,2,3},{1,1,3},{1,2,4},{1,1,2},{2,3,4}
    };

    cout << maxNumEdgesToRemove(n, edges) << endl;
    return 0;
}