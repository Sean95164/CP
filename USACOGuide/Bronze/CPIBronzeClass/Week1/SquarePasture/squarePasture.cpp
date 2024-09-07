#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("square.in", "r", stdin);
    // freopen("square.out", "w", stdout);
    
    int a_x1, a_y1, a_x2, a_y2;
    int b_x1, b_y1, b_x2, b_y2;

    cin >> a_x1 >> a_y1 >> a_x2 >> a_y2;
    cin >> b_x1 >> b_y1 >> b_x2 >> b_y2;

    int max_width = max(a_x2, b_x2) - min(a_x1, b_x1);
    int max_height = max(a_y2, b_y2) - min(a_y1, b_y1);

    int max_squareLen = max(max_width, max_height);
    cout << max_squareLen * max_squareLen << "\n";
    return 0;
}