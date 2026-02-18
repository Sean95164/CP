#include <bits/stdc++.h>

using namespace std;

struct Location
{
    long long x, y, t;
};

bool reachable(const Location &l1, const Location &l2) {
    long long dt = l1.t - l2.t;
    long long dx = l1.x - l2.x;
    long long dy = l1.y - l2.y;
    return dt*dt >= dx*dx + dy*dy;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int g, n;
    cin >> g >> n;
    vector<Location> grazings(g);
    vector<Location> cows(n);
    for (int i = 0; i < g; i++) {
        cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    }
    for (int i = 0; i < n; i++) {
        cin >> cows[i].x >> cows[i].y >> cows[i].t;
    } 
    sort(grazings.begin(), grazings.end(), [](const Location &l1, const Location &l2) {
        return l1.t < l2.t;
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k = lower_bound(grazings.begin(), grazings.end(), cows[i].t, [](const Location &loc, const int &time) {
            return loc.t < time;
        }) - grazings.begin();
        
        // cout << k << "\n";
        bool innocent = false;
        for (int j = k-1; j <= k; j++) {
            if (0 <= j && j < g) {
                innocent |= !reachable(grazings[j], cows[i]);
            }
        }
        ans += innocent;
    }
    cout << ans << "\n";
    return 0;
}