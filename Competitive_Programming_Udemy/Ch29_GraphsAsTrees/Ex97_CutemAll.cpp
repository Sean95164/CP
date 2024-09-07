#include<bits/stdc++.h>
using namespace std;

int dfs(map<int, vector<int>> tree, int cur, int par, int &ans) {
    if (tree[cur].size() == 1) {
        return 1;
    }

    int total = 0;
    for (auto nbr : tree[cur]) {
        if (nbr != par) {
            int cnt = dfs(tree, nbr, cur, ans);
            total += cnt;
            if (cnt % 2 == 0) {
                ans++;
            }
        }
    }

    total++;
    return total;
}

int solve(int n, vector<vector<int>> edges) {
    if (n&1) {
        return -1;
    }

    map<int, vector<int>> tree;
    for (auto p : edges) {
        int x = p[0];
        int y = p[1];
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    int ans = 0;
    dfs(tree, 1, 0, ans);
    return ans;
}

int main() {

    int n = 4;
    vector<vector<int>> edges = {
        {2, 4},
        {4, 1},
        {3, 1}
    };

    cout << solve(n, edges) << endl; // 1

    return 0;
}