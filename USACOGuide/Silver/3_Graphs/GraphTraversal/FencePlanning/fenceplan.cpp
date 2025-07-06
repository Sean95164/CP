#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;

    pair<int ,int> cows[n+1]; // x, y
    int x, y;
    for(int i = 1; i <= n; i++) {
        cin >> x >> y;
        cows[i] = {x, y};
    }

    map<int, vector<int>> gr;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }

    // bfs
    // init
    long long ans = LONG_LONG_MAX;
    vector<bool> visited(n+1, false);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            q.push(i);
            visited[i] = true;
            int top = cows[i].second, bottom = cows[i].second, left = cows[i].first, right = cows[i].first;
            // find all cow connected to i
            while(!q.empty()) {
                int cur = q.front();
                q.pop();
                for (int nbr : gr[cur]) {
                    if (!visited[nbr]) {
                        q.push(nbr);
                        visited[nbr] = true;
                        // update four extreme
                        top = max(top, cows[nbr].second);
                        bottom = min(bottom, cows[nbr].second);
                        left = min(left, cows[nbr].first);
                        right = max(right, cows[nbr].first);
                    }
                }
            }
            long long tmp = 0;
            tmp += (top - bottom) * 2;
            tmp += (right - left) * 2;
            // cout << "check: " << bottom << " " << top << " " << left << " " << right << endl;
            ans = min(ans, tmp);
        }

    }

    cout << ans << "\n";
    return 0;
}