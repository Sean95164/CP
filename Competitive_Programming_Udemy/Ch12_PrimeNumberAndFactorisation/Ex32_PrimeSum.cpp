#include <bits/stdc++.h>

using namespace std;

void primeSieve(vector<int> &prime, int n) {
    prime[1] = prime[0] = 0;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
}

int solve(int n){
    vector<int> prime(n+1, 1);
    primeSieve(prime, n);

    int ans = 0;
    // only check some prime plus 2 (any prime is odd number except 2)
    // two odd primes are added always not a prime. 
    for (int i = 3; i <= n-2; i++) {
        if (prime[i] && prime[i+2]) {
            ans++;
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