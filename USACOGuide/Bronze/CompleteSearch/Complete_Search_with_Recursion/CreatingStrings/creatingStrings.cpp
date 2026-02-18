#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);


    string src;
    cin >> src;

    sort(src.begin(), src.end());
    set<string> ans;

    do {
        ans.insert(src);
    } while(next_permutation(src.begin(), src.end()));


    cout << ans.size() << "\n";
    for (string s : ans) {
        cout << s << "\n";
    }

    return 0;
}