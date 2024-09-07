#include<bits/stdc++.h>
using namespace std;

int minTaps(int n, vector<int> ranges) {
    // first: start, second: end
    vector<pair<int, int>> taps;

    int start, end;
    for (int i = 0; i < n + 1; i++) {
        start = (i - ranges[i] < 0 ? 0 : i - ranges[i]);
        end = (i + ranges[i] > n ? n : i + ranges[i]);
        taps.push_back({start, end});
    }

    // for (auto p : taps) {
    //     cout << p.first << " " << p.second << endl;
    // }

    sort(taps.begin(), taps.end());

    // select
    int cur = 0, prev = 0;
    int cnt = 0;
    while(cur != n) {
        prev = cur;
        for (int i = 0; i < n + 1; i++) {
            if (taps[i].first > prev || taps[i].second < prev) {
                continue;
            }
            
            cur = max(cur, taps[i].second);
        }

        if (cur == prev) {
            return -1;
        }

        // cout << "cur: " << cur << endl;
        cnt++;
    }

    return cnt;
}

int main() {
    int n = 5;
    vector<int> ranges = {3, 4, 1, 1, 0, 0};
    cout << minTaps(n, ranges) << endl; // 1
    cout << minTaps(3, {0, 0, 0, 0}) << endl; // -1
    cout << minTaps(4, {0, 1, 1, 0, 3}) << endl; // 2
    return 0;
}