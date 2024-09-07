#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>> roads,int n){
    map<int, vector<pair<int, int>>> gr;
    int x, y, w;
    for (auto p : roads) {
        x = p[0];
        y = p[1];
        w = p[2];
        gr[x].push_back({y, w});
        gr[y].push_back({x, w});
    }

    // Dijkstra
    set<pair<int, int>> s; // {dist, number}
    vector<int> dist(n + 1, INT_MAX);

    // vector "past" to record previous vertex
    vector<int> past(n + 1, 0);

    // init
    s.insert({0, 1});
    dist[1] = 0;

    while(!s.empty()) {
        auto it = s.begin();
        int curNum = it->second;
        int curDist = it->first;
        s.erase(it);

        for (auto nbrPair : gr[curNum]) {
            int nbr = nbrPair.first;
            int edgeValue = nbrPair.second;

            int newCost = curDist + edgeValue;
            if (newCost < dist[nbr]) {
                past[nbr] = curNum;
                dist[nbr] = newCost;
                s.insert({dist[nbr], nbr});
            }

        }
    }

    // Output processing
    stack<int> tmp;
    while(n != 0) {
        tmp.push(n);
        n = past[n];
    }

    vector<int> ans;
    while(!tmp.empty()) {
        ans.push_back(tmp.top());
        tmp.pop();
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> roads = {
        {1, 2, 2},
        {2, 5, 5},
        {2, 3, 4},
        {1, 4, 1},
        {4, 3, 3},
        {3, 5, 1}
    };

    vector<int> ans = shortestPath(roads, n);

    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}