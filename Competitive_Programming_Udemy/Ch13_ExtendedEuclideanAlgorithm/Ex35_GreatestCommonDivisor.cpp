#include <bits/stdc++.h>

using namespace std;

int solve(int a,int b){
    if (b == 0) {
        return a;
    }
    return solve(b, a%b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << solve(a, b) << endl;
    return 0;
}