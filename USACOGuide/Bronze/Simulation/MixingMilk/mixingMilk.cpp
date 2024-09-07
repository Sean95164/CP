#include <bits/stdc++.h>

using namespace std;

void aToB(vector<pair<int, int>> &cow, int from, int to) {
    int remaining_capacity = cow[to].first - cow[to].second;

    int max_milk = cow[from].second;
    if (remaining_capacity >= max_milk) {
        cow[from].second = 0;
        cow[to].second += max_milk;
    }
    else {
        cow[to].second = cow[to].first;
        cow[from].second -= remaining_capacity;
    }
}

int main() {
    // freopen("mixmilk.in", "r", stdin);
    // freopen("mixmilk.out", "w", stdout);

    vector<pair<int, int>> cow(3);

    int c, m;
    for (int i = 0; i < 3; i++) {
        cin >> c >> m;
        cow[i] = {c, m};
    }

    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 1) {
            aToB(cow, 0, 1);
        }
        else if (i % 3 == 2) {
            aToB(cow, 1, 2);
        }
        else {
            aToB(cow, 2, 0);
        }
    }

    for (int i = 0; i < 3; i++) {
        cout << cow[i].second << endl;
    }

    return 0;
}