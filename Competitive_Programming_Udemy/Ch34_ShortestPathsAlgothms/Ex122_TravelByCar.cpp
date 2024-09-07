#include<bits/stdc++.h>
using namespace std;

#define INF 1e9

vector<int> travelByCar(int n,int l, vector<vector<int>> edges ,vector<vector<int>> queries) {
    // Using Floyd-Warshall algorithm
    // init
    vector<vector<int>> fuel(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
        fuel[i][i] = 0;
    }

    int u, v, cost;
    for (auto edge : edges) {
        u = edge[0];
        v = edge[1];
        cost = edge[2];

        dp[u][v] = cost;
        dp[v][u] = cost;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][j] > dp[i][k] + dp[k][j]) {
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (dp[i][j] <= l) {
                fuel[i][j] = 1;
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (fuel[i][j] > fuel[i][k] + fuel[k][j]) {
                    fuel[i][j] = fuel[i][k] + fuel[k][j];
                }
            }
        }
    }

    // deal with queries
    vector<int> ans;
    int src, des;
    for (auto p : queries) {
        src = p[0];
        des = p[1];
        if (fuel[src][des] == INF) {
            ans.push_back(-1);
        }
        else {
            ans.push_back(fuel[src][des] - 1);
        }
        
    }

    return ans;
}