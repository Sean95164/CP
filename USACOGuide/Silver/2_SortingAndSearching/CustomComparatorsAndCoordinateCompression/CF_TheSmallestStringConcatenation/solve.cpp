#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // aaada
    // aaa
    // aaaad
    // ans: aaaaaaadaaada

    // xxaa
    // xxaabbxx
    // ans: xxaaxxaabbxx
    // ans: xxaabbxxxxaa
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    sort(s.begin(), s.end(), [](const string &s1, const string &s2) {
        return (s1 + s2) < (s2 + s1);
    });
    for (string str : s) {
        cout << str;
    }
    cout << "\n";
    return 0;
}