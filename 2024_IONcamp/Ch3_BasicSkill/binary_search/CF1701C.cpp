#include <bits/stdc++.h>
#define int long long

using namespace std;

bool check(int n, int m, vector<int> count, int mid) {
    vector<int> peo(n+1, mid);

    // each people do their proficent best for more
    for (int i = 1; i <= n; i++) {
        int remain = peo[i] - count[i];
        if (remain < 0) {
            count[i] -= peo[i];
            peo[i] = 0;
        }
        else {
            peo[i] -= count[i];
            count[i] = 0;
        }
    }

    // count each person can do how many task and remaining tasks
    int canDo = 0;
    for (int i = 1; i <= n; i++) {
        canDo += peo[i] / 2;
    }

    int tasks = 0;
    for (int i = 1; i <= m; i++) {
        tasks += count[i];
    }

    if (canDo >= tasks) {
        return true;
    }
    else {
        return false;
    }
}

int32_t main() {
    int t;
    cin >> t;

    int n, m;
    while(t--) {
        cin >> n >> m;
        vector<int> count(m+1, 0);
        int x;
        for (int i = 1; i <= m; i++) {
            cin >> x;
            count[x]++;
        }

        // binary search the mininum cost time
        int l = 1;
        int r = 2 * m;
        while(l != r) {
            int mid = (l + r) / 2;
            if (check(n, m, count, mid)) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }

        cout << r << "\n";
    }
    

    return 0;
}