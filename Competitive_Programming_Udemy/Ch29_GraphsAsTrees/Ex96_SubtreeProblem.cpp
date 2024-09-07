#include<bits/stdc++.h>
using namespace std;

int dfs(map<int, vector<int>> tree, int cur, int par, vector<int> &count) {
    if (count[cur] != 0) {
        return count[cur];
    }

    if (tree[cur].size() == 1) {
        count[cur] = 1;
        return 1;
    }

    for (auto nbr : tree[cur]) {
        if (nbr != par) {
            count[cur] += dfs(tree, nbr, cur, count);
        }
    }
    count[cur]++;
    return count[cur];
}

vector<int> subtreeProblem (int n, vector<vector<int>> edges, vector<int> queries) {
    map<int, vector<int>> tree;
    for (auto p : edges) {
        int ui = p[0];
        int vi = p[1];
        tree[ui].push_back(vi);
        tree[vi].push_back(ui);
    }
    
    vector<int> count(n+1, 0);

    dfs(tree, 1, 0, count);

    int nq = queries.size();
    vector<int> ans;
    for (int i = 0; i < nq; i++) {
        ans.push_back(count[queries[i]]);
    }

    return ans;
}

int main() {
    int n = 5;
    vector<vector<int>> edges = {
        {1, 2},
        {1, 3},
        {3, 4},
        {3, 5}
    };

    vector<int> queries = {1, 2, 3, 4, 5};
    vector<int> ans = subtreeProblem(n, edges, queries);

    for (auto x : ans) {
        cout << x << endl;
    }
    return 0;
}