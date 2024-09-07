#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int solve(int a, string b){
    int n = b.size();
    int val = 0;
    for (int i = 0; i < n; i++) {
        val = (val * 10 + (b[i] - '0')) % a;
    }
    return gcd(a, val);
}

int main() {
    int a = 10;
    string b = "11";
    cout << solve(a, b) << endl;
}