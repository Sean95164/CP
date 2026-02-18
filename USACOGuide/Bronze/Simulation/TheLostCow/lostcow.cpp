#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("lostcow.in", "r", stdin);
    freopen("lostcow.out", "w", stdout);

    int x, y;
    cin >> x >> y;
    int cur = x;
    int num = 1;
    int total = 0;
    while (true) {
        int next = x + num;
        if (min(next, cur) <= y && y <= max(next, cur)) {
            total += abs(cur - y);
            break;
        }
        total += abs(next - cur);
        cur = next;
        num *= -2;
    }

    cout << total << "\n";
    return 0;
}