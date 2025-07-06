#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> gr;

bool connected(const vector<int> &n1, const vector<int> &n2) {
    long long dx = n1[0] - n2[0];
    long long dy = n1[1] - n2[1];

    long long dist = dx*dx + dy*dy;
    return n1[2]*n1[2] >= dist;
}

int dfs(int cur, vector<bool> &visited) {
    visited[cur] = true;
    
    int ans = 0;
    for (auto nbr : gr[cur]) {
        if (!visited[nbr]) {
            ans += dfs(nbr, visited);
        }
    }

    return ans + 1;
}

int main() {
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    
    int n;
    cin >> n;
    
    vector<vector<int>> node(n);
    int x, y, p;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> p;
        node[i] = {x, y, p};
    }

    
    for (int i = 0; i < n; i++) {
        vector<int> n1 = node[i];
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            vector<int> n2 = node[j];
            if (connected(n1, n2)) {
                gr[i].push_back(j);
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        vector<bool> visited(n, false);
        int tmp = dfs(i, visited);
        ans = max(ans, tmp);
    }

    cout << ans << "\n";
    return 0;
}