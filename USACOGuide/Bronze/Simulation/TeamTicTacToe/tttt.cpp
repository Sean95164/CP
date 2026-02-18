#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);

    vector<vector<char>> t(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> t[i][j];
        }
    }

    set<char> single;
    set<pair<char, char>> team;
    // check for rows
    for (int i = 0; i < 3; i++) {
        set<char> s;
        for (int j = 0; j < 3; j++) {
            s.insert(t[i][j]);
        }
        if (s.size() == 1) single.insert(*s.begin());
        if (s.size() == 2) {
            auto it = s.begin();
            char a = *it;
            it++;
            char b = *it;
            if (a > b) swap(a, b);
            team.insert({a, b});
        }
    }

    // check for cols
    for (int j = 0; j < 3; j++) {
        set<char> s;
        for (int i = 0; i < 3; i++) {
            s.insert(t[i][j]);
        }
        if (s.size() == 1) single.insert(*s.begin());
        if (s.size() == 2) {
            auto it = s.begin();
            char a = *it;
            it++;
            char b = *it;
            if (a > b) swap(a, b);
            team.insert({a, b});
        }
    }
    // check for diagonals
    set<char> s;
    s.insert(t[0][0]); s.insert(t[1][1]); s.insert(t[2][2]);
    if (s.size() == 1) single.insert(*s.begin());
    if (s.size() == 2) {
        auto it = s.begin();
        char a = *it;
        it++;
        char b = *it;
        if (a > b) swap(a, b);
        team.insert({a, b});
    }
    s.clear();

    s.insert(t[0][2]); s.insert(t[1][1]); s.insert(t[2][0]);
    if (s.size() == 1) single.insert(*s.begin());
    if (s.size() == 2) {
        auto it = s.begin();
        char a = *it;
        it++;
        char b = *it;
        if (a > b) swap(a, b);
        team.insert({a, b});
    }
    s.clear();
    
    cout << single.size() << "\n" << team.size() << "\n";
    return 0;
}