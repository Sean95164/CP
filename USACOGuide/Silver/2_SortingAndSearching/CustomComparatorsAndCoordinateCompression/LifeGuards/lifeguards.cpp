#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    
    int n;
    cin >> n;

    vector<pair<int, int>> guards(n);

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        guards[i] = {a, b};
    }
    sort(guards.begin(), guards.end());

    int total = 0;
    int cur_start = guards[0].first;
    int cur_end = guards[0].second;
    
    bool submerged = false;
    for (int i = 1; i < n; i++) {
        // case for overlapping
        if (guards[i].first < cur_end) {
            cur_end = max(cur_end, guards[i].second);
            if (guards[i].second < cur_end) {
                submerged = true;
            }
        }        

        // case for seperating
        if (guards[i].first > cur_end) {
            total += cur_end - cur_start;
            cur_start = guards[i].first;
            cur_end = guards[i].second;
        }
    }

    total += cur_end - cur_start;

    if (submerged) {
        cout << total << "\n";
        return 0;
    }
    // find the minimum along time guard, and fire it

    // deal with edge case
    int min_alongTime = INT_MAX;

    
    for (int i = 1; i < n-1; i++) {
        int left = 0;
        if (i > 0) {
            left = max(0, guards[i-1].second - guards[i].first);
        }
        
        int right = 0;
        if (i < n-1) {
            right = max(0, guards[i].second - guards[i+1].first);
        }
        int alone = max(0, guards[i].second - guards[i].first - left - right);
        min_alongTime = min(min_alongTime, alone);
    }
    
    cout << total - min_alongTime << "\n";
    return 0;
}