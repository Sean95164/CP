#include<bits/stdc++.h>
using namespace std;

int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    int tmp = power(a, b/2);
    if (b&1) {
        return a * tmp * tmp;
    }
    return tmp * tmp;
}

int __solve(int target, int n, int index) {
    if (target == 0) {
        return 1;
    }
    
    int cur = power(index, n);
    if (cur > target) {
        return 0;
    }

    return __solve(target - cur, n, index + 1) + 
            __solve(target, n, index + 1);
}

int solve(int x,int n){
    return __solve(x, n, 1);
}

int main() {
    int x = 97;
    int n = 6;
    cout << solve(x, n) << endl;
    return 0;
}