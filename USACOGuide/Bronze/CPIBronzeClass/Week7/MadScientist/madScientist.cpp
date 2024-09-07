#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("breedflip.in", "r", stdin);
    // freopen("breedflip.out", "w", stdout);


    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    bool start = false;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (s1[i] == s2[i]) {
            start = false;
        }
        else {
            if (!start) {
                start = true;
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}