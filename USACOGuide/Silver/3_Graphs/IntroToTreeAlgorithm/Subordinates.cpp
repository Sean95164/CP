#include <bits/stdc++.h>

using namespace std;

map<int, vector<int>> tree;
vector<int> ans;

void solve(int cur, int par) {
    if (tree[cur].size() == 0) {
        ans[cur] = 0;
        return;
    }

    int tmp = 0;
    for (auto next : tree[cur]) {
        if (next != par) {
            solve(next, cur);
            tmp += ans[next] + 1;
        }
    }


    ans[cur] = tmp;
}


int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n;
    cin >> n;

    ans.resize(n+1, -1);
    int to;
    for (int i = 2; i <= n; i++) {
        cin >> to;
        tree[i].push_back(to);
        tree[to].push_back(i);
    }

    solve(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i==n];
    }  
    return 0;
}