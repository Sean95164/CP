#include <bits/stdc++.h>

using namespace std;

bool ok(int n, const vector<pair<long long, long long>> &segs, long long dist) {
    int total = 1;
    int cur_seg = 0;
    long long pos = segs[0].first;
    for (int i = 1; i < n; i++) {
        pos += dist;
        
        while (cur_seg < (int) segs.size() && pos > segs[cur_seg].second) {
            cur_seg++;
        }
        if (cur_seg == (int) segs.size()) {
            break;
        }

        bool inSeg = false;
        if (pos >= segs[cur_seg].first) {
            inSeg = true;
        }

        if (!inSeg) {
            pos = segs[cur_seg].first;
        }

        total++;
    }
    // cout << dist << " " << total << "\n";
    return total == n;
}

int main() {
    freopen("socdist.in", "r", stdin);
    freopen("socdist.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> segs(m);
    for (int i = 0; i < m; i++) {
        cin >> segs[i].first >> segs[i].second;
    }
    sort(segs.begin(), segs.end());

    long long left = 1, right = 1e18 + 1;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        if (ok(n, segs, mid)) {
            left = mid+1;
        }
        else {
            right = mid;
        }
    }

    cout << left - 1 << "\n";
    return 0;
}