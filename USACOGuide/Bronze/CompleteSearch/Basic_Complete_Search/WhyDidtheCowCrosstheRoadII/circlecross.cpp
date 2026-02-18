#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    const int n = 52;
    string s;
    cin >> s;

    int pairs = 0;
    for (int i = 0; i < n/2; i++) {
        for (int j = i+1; j < n/2; j++) {
            char a = 'A' + i;
            char b = 'A' + j;
            vector<char> t;
            for (int k = 0; k < n; k++) {
                if (s[k] == a || s[k] == b) {
                    t.push_back(s[k]);
                }
            }
            if (t[0] == t[2] && t[1] == t[3]) {
                pairs++;
            }
        }
    }

    cout << pairs << "\n";
    return 0;
}