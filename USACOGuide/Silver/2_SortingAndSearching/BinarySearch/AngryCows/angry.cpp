#include <bits/stdc++.h>

using namespace std;

bool ok(const vector<int> &pos, int r, int k) {
    int n = pos.size();
    int used = 0;
    int i = 0;
    while(i < n) {
        used++;
        int end = pos[i] + 2*r;
        while(i < n && pos[i] <= end) {
            i++;
        }
    }

    return used <= k;
}

int main() {
    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());
    int left = 0, right = pos[n-1];
    while(left < right) {
        int mid = left + (right - left) / 2;
        if (ok(pos, mid, k)) {
            right = mid;
        }
        else {
            left = mid+1;
        }
    }

    cout << left << "\n";
    return 0;
}