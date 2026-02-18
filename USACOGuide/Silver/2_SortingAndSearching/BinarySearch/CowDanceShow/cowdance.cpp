#include <bits/stdc++.h>

using namespace std;

bool ok (const vector<int> &cows, int k, int t) {
    priority_queue<int, vector<int>, greater<int>> stage;
    int n = cows.size();
    for (int i = 0; i < k; i++) {
        stage.push(cows[i]);
    }

    int pos = k;
    while(pos < n) {
        int finish_time = stage.top();
        stage.pop();
        stage.push(finish_time + cows[pos]);
        pos++;
    }

    while(stage.size() != 1) {
        stage.pop();
    }
    
    // cout << k << " " << stage.top() << "\n";
    return stage.top() <= t;
}

int main() {
    freopen("cowdance.in", "r", stdin);
    freopen("cowdance.out", "w", stdout);

    int n, t;
    cin >> n >> t;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows[i];
    }

    int l = 1, r = n+1;
    while(l < r) {
        int mid = l + (r-l) / 2;
        if (!ok(cows, mid, t)) {
            l = mid+1;
        }
        else {
            r = mid;
        }
    }
    cout << l << "\n";
    return 0;
}