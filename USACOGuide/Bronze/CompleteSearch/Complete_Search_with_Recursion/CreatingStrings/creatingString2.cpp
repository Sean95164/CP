#include <bits/stdc++.h>

using namespace std;

string src;
set<string> ans;

void solve(string cur, vector<bool> used) {
    if (cur.size() == src.size()) {
        ans.insert(cur);
        return;
    }

    int n = src.size();
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        used[i] = true;
        solve(cur + src[i], used);
        used[i] = false;
    }
}

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    cin >> src;
    
    vector<bool> used(src.size(), false);
    solve("", used);


    cout << ans.size() << "\n";
    for (string s : ans) {
        cout << s << "\n";
    }

    return 0;
}