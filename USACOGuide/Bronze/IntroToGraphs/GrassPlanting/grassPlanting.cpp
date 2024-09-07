#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("planting.in", "r", stdin);
    // freopen("planting.out", "w", stdout);

    int n;
    cin >> n;

    map<int, vector<int>> gr;

    int x, y;
    for (int i = 0; i < n-1; i++) {
        cin >> x >> y;
        x--;
        y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (int) gr[i].size() + 1);
    }
    
    cout << ans << endl;

    return 0;
}