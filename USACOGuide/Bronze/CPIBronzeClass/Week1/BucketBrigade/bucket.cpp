#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("buckets.in", "r", stdin);
    // freopen("buckets.out", "w", stdout);

    vector<string> gr;
    string s;
    for (int i = 0; i < 10; i++) {
        cin >> s;
        gr.push_back(s);
    }
    int b_x, b_y;
    int l_x, l_y;
    int r_x, r_y;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            char cha = gr[i][j];
            if (cha == 'B') {
                b_x = i;
                b_y = j;
            }
            else if (cha == 'L') {
                l_x = i;
                l_y = j;
            }
            else if (cha == 'R') {
                r_x = i;
                r_y = j;
            }
        }
    }
    int height = abs(b_x - l_x);
    int width = abs(b_y - l_y);

    bool inHorizontal = (b_x == l_x && l_x == r_x) && ((b_y < r_y && r_y < l_y) || (l_y < r_y && r_y < b_y));
    bool inVertical = (b_y == l_y && l_y == r_y) && ((b_x < r_x && r_x < l_x) || (l_x < r_x && r_x < b_x));
    if (inVertical || inHorizontal) {
        cout << height + width - 1 + 2 << endl;
    }
    else {
        cout << height + width - 1 << endl;
    }
    
    return 0;
}