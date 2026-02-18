#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    cin >> n;
    vector<int> shuffle(n);
    for (int i = 0; i < n; i++) {
        cin >> shuffle[i];
        shuffle[i]--;
    }

    vector<string> id(n);
    for (int i = 0; i < n; i++) {
        cin >> id[i];
    }

    for (int t = 0; t < 3; t++) {
        vector<string> tmp(n);
        for (int i = 0; i < n; i++) {
            tmp[i] = id[shuffle[i]];
        }
        id = tmp;
    }

    for (const string &s : id) {
        cout << s << "\n";
    }
    return 0;
}