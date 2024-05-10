#include <bits/stdc++.h>

using namespace std;


int sumOfDigit(long long num) {
    int sum = 0;
    while (num) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int solve2 (long long A) {
    int S = sumOfDigit(A);
    if (S < 10) return S;
    else return solve2(S);
}

int solve(long long A, long long N){
    int ans = 1;
    for (int i = 0; i < N; i++) {
        ans = solve2(ans * solve2(A));
    }

    return ans;
}

int main() {
    cout << solve(7, 2) << endl;
    return 0;
}