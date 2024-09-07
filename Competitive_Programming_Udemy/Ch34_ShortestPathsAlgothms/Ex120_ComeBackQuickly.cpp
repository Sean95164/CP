#include<bits/stdc++.h>
using namespace std;

int dijktra(map<int, vector<pair<int, int>>> gr, int n, int src, int des) {
    vector<int> dist(n+1, INT_MAX);
    set<pair<int, int>> s;

    // init
    s.insert({0, src});

    while(!s.empty()) {
        auto it = s.begin();
        int num = it->second;
        int distCur = it->first;
        s.erase(it);

        for (auto nbrPair : gr[num]) {
            int edgeValue = nbrPair.second;
            int nbr = nbrPair.first;

            int total = edgeValue + distCur;
            if (total < dist[nbr]) {
                dist[nbr] = total;
                s.insert({dist[nbr], nbr});
            }
        }
    }

    return dist[des];
}


vector<int> solve(int n,int m, vector<vector<int>> road) {
    map<int, vector<pair<int, int>>> gr;
    int a, b, w;
    for (auto p : road) {
        a = p[0];
        b = p[1];
        w = p[2];
        gr[a].push_back({b, w});
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int cost = dijktra(gr, n, i, i);
        if (cost == INT_MAX) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(cost);
        }
    }

    return ans;
}

int main() {
    int n = 4;
    int m = 4;
    vector<vector<int>> road = {
        {1, 2, 5},
        {2, 3, 10},
        {3, 1, 15},
        {4, 3, 20}
    };
    vector<int> ans = solve(n, m, road);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}