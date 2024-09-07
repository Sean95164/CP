#include<bits/stdc++.h>
using namespace std;

int dijkstra(map<int, vector<pair<int, int>>> gr, int n, int src) {
    // {dist, nodeNumber}
    set<pair<int, int>> s;
    vector<int> dist(n + 1, INT_MAX);

    // init
    dist[src] = 0;
    s.insert({0, src});

    while(!s.empty()) {
        auto f = s.begin();
        int curNum = f->second;
        int curDist = f->first;

        s.erase(f);
        for (auto p : gr[curNum]) {
            int nbr = p.first;
            int edgeValue = p.second;

            if (curDist + edgeValue < dist[nbr]) {
                auto it = s.find({dist[nbr], nbr});
                if (it != s.end()) {
                    s.erase(it);
                }
                dist[nbr] = curDist + edgeValue;
                s.insert({dist[nbr], nbr});
                
            }
        }
    }

    int cost = INT_MIN;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) {
            return -1;
        }
        cost = max(cost, dist[i]);
    }

    return cost;
}

int networkDelayTime(vector<vector<int>> times, int n, int k) {
    map<int, vector<pair<int, int>>> gr;

    int u, v, w;
    for (auto p : times) {
        u = p[0];
        v = p[1];
        w = p[2];
        gr[u].push_back({v, w});
    }

    

     return dijkstra(gr, n, k);

}

int main() {
    vector<vector<int>> times {
        {2, 1, 1},
        {2, 3, 1},
        {3, 4, 1}
    };
    int n = 4;
    int k = 2;
    cout << networkDelayTime(times, n, k) << endl;
    return 0;
}