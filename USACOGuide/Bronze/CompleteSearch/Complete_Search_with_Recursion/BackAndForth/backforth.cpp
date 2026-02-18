#include <bits/stdc++.h>

using namespace std;

set<int> nums;

void rec(vector<int> b1, vector<int> b2, int t1, int t2, int day) {
    if (day == 4) {
        nums.insert(t1);
        return;
    }

    for (int i = 0; i < (int) b1.size(); i++) {
        vector<int> next_1 = b1;
        vector<int> next_2 = b2;
        int num = next_1[i];
        next_1.erase(next_1.begin()+i);
        next_2.push_back(num);
        rec(next_2, next_1, t2+num, t1-num, day+1);
    }
}

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    const int n = 10;
    vector<int> b1(n);
    vector<int> b2(n);
    for (int i = 0; i < n; i++) {
        cin >> b1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b2[i];
    }

    rec(b1, b2, 1000, 1000, 0);
    cout << nums.size() << "\n";
    return 0;
}