#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

// Determine whether have any relative prime
bool isGoodArray(vector<int> nums) {
    int ans = 0;
    for (auto x:nums) {
        ans = gcd(ans, x);
    }
    return ans == 1;
}

int main() {
    cout << isGoodArray({12, 5, 7, 23}) << endl;
    return 0;
}