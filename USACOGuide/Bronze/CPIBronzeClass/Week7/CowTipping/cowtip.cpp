#include <bits/stdc++.h>

using namespace std;

void flip(vector<string> &farm, int a, int b) {
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (farm[i][j] == '1') {
                farm[i][j] = '0';
            }
            else {
                farm[i][j] = '1';
            }
        }
    }
}

int main() {
    // freopen("cowtip.in", "r", stdin);
    // freopen("cowtip.out", "w", stdout);
    
    int n;
    cin >> n;

    vector<string> farm(n);
    for (int i = 0; i < n; i++) {
        cin >> farm[i];
    }    

    int times = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (farm[i][j] == '1') {
                flip(farm, i, j);
                times++;
            }
        }
    }

    cout << times << "\n";
    return 0;
}