#include <bits/stdc++.h>

using namespace std;

map<string, vector<string>> near;

bool check(const vector<string> &all) {
    int n = all.size();

    for (int i = 0; i < n; i++) {
        string cur = all[i];

        if (near.count(cur) == 0) {
            continue;
        }
        
        string left = "";
        string right = "";

        if (i != 0) {
            left = all[i-1];
        }

        if (i != n - 1) {
            right = all[i+1];
        }

        for (auto s : near[cur]) {
            if (s != left && s != right) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    freopen("lineup.in", "r", stdin);
    freopen("lineup.out", "w", stdout);

    int n;
    cin >> n;
    string s1, s2, ignore;

    near.clear();
    for (int i = 0; i < n; i++) {
        cin >> s1;

        for (int j = 0; j < 4; j++) {
            cin >> ignore;
        }

        cin >> s2;

        near[s2].push_back(s1);
    }

    vector<string> all = {"Bessie","Buttercup","Belinda","Beatrice","Bella","Blue","Betsy","Sue"};

    sort(all.begin(), all.end());

    do {
        if (check(all)) {
            for (auto s : all) {
                cout << s << "\n";
            }
            break;
        }
    } while(next_permutation(all.begin(), all.end()));

    return 0;
}