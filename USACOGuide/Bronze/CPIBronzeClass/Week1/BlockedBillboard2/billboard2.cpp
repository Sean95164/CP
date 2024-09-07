#include <bits/stdc++.h>

using namespace std;

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    bool leftRight = (y3 < y1) && (y4 > y2) && ((x3 < x2 && x2 < x4) || (x3 < x1 && x1 < x4));
    bool topBottom = (x3 < x1) && (x4 > x2) && ((y3 < y2 && y2 < y4) || (y3 < y1 && y1 < y4));
    return leftRight || topBottom;
}

int main() {
    // freopen("billboard.in", "r", stdin);
    // freopen("billboard.out", "w", stdout);
    
    int lawn_x1, lawn_y1, lawn_x2, lawn_y2;
    int b_x1, b_y1, b_x2, b_y2;

    cin >> lawn_x1 >> lawn_y1 >> lawn_x2 >> lawn_y2;
    cin >> b_x1 >> b_y1 >> b_x2 >> b_y2;

    int ans = (lawn_x2 - lawn_x1) * (lawn_y2 - lawn_y1);

    if (check(lawn_x1, lawn_y1, lawn_x2, lawn_y2, b_x1, b_y1, b_x2, b_y2)) {
        int top = min(lawn_y2, b_y2);
        int bottom = max(lawn_y1, b_y1);
        int right = min(lawn_x2, b_x2);
        int left = max(lawn_x1, b_x1);

        ans -= (top - bottom) * (right - left);
    }

    cout << ans << endl;
    return 0;
}