#include <bits/stdc++.h>

using namespace std;

bool overlap(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    return (x2 > x3) && (x1 < x4) && (y2 > y3) && (y1 < y4);
}

int main() {
    // freopen("billboard.in", "r", stdin);
    // freopen("billboard.out", "w", stdout);
    
    int b1_x1, b1_y1, b1_x2, b1_y2;
    int b2_x1, b2_y1, b2_x2, b2_y2;
    int t_x1, t_y1, t_x2, t_y2;
    cin >> b1_x1 >> b1_y1 >> b1_x2 >> b1_y2;
    cin >> b2_x1 >> b2_y1 >> b2_x2 >> b2_y2;
    cin >> t_x1 >> t_y1 >> t_x2 >> t_y2;

    int ans = 0;
    ans += (b1_x2 - b1_x1) * (b1_y2 - b1_y1);
    ans += (b2_x2 - b2_x1) * (b2_y2 - b2_y1);

    if (overlap(b1_x1, b1_y1, b1_x2, b1_y2, t_x1, t_y1, t_x2, t_y2)) {
        int top = min(b1_y2, t_y2);
        int bottom = max(b1_y1, t_y1);
        int left = max(b1_x1, t_x1);
        int right = min(b1_x2, t_x2);
        ans -= (top - bottom) * (right - left);
    }

    if (overlap(b2_x1, b2_y1, b2_x2, b2_y2, t_x1, t_y1, t_x2, t_y2)) {
        int top = min(b2_y2, t_y2);
        int bottom = max(b2_y1, t_y1);
        int left = max(b2_x1, t_x1);
        int right = min(b2_x2, t_x2);
        ans -= (top - bottom) * (right - left);
    }

    cout << ans << endl;
    return 0;
}