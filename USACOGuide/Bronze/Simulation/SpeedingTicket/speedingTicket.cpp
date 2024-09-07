#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<int> road(101), driver(101);

    int start = 1;
    int end = 1;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        end += x;
        fill(road.begin() + start, road.begin() + end, y);
        start = end;
    }

    start = 1;
    end = 1;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        end += x;
        fill(driver.begin() + start, driver.begin() + end, y);
        start = end;
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        if (driver[i] > road[i]) {
            ans = max(ans, driver[i] - road[i]);
        }
    }

    cout << ans << endl;
    return 0;
}