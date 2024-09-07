#include <bits/stdc++.h>

using namespace std;

int solve(int n){
    int ans = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            int a = i;
            int b = n / a;
            if ((a + b) % 2 == 0) {
                ans++;
            }
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}