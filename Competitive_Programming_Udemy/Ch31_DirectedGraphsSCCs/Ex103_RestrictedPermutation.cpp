#include<bits/stdc++.h>
using namespace std;

vector<bool> visited(2 * 1e5 + 5, false);

bool dfs(map<int, vector<int>> gr, vector<int> &ans, int cur, int st) {
    visited[cur] = true;
    for (auto nbr : gr[cur]) {
        if (nbr == st) {
            return false;
        }

        if (!visited[nbr]) {
            if (!dfs(gr, ans, nbr, st)) {
                return false;
            }
        }
    }

    ans.push_back(cur);
    return true;
}

vector<int> solve(int n,int m, vector<vector<int>> arr) {
    set<vector<int>> s;
    int a, b;
    for (auto edge : arr) {
        a = edge[0];
        b = edge[1];
        s.insert({a, b});
    }

    map<int, vector<int>> gr;
    for (auto edge : s) {
        a = edge[0];
        b = edge[1];

        gr[a].push_back(b);
    }

    vector<int> ans;
    for (int i = n; i >= 1; i--) {
        if (!visited[i]) {
            if (!dfs(gr, ans, i, i)) {
                return {};
            }
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    int n = 3;
    int m = 3;
    vector<vector<int>> arr = {
        {1, 2}, {1, 3}, {2, 3}
    };

    vector<int> ans = solve(n, m, arr);
    for (auto x : ans) {
        cout << x << " ";
    }

    cout << endl;
    return 0;
}