#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("sample.in", "r", stdin);
    // freopen("sample.out", "w", stdout);

    int n;
    cin >> n;

    string s;
    cin >> s;
    s = " " + s;
    int flip = 0;

    for (int i = n; i >= 1; i-=2) {
        if (s[i] == s[i-1]) continue;
        if (s[i-1] == 'G' && flip % 2 == 0) {
            flip++;
        }
        else if (s[i-1] == 'H' && flip % 2 == 1) {
            flip++;
        }
    }

    cout << flip << endl;
    return 0;
}