#include <bits/stdc++.h>

using namespace std;
#define ll long long

void primeSieve(vector<int> &sieve) {
    int n = sieve.size();
    sieve[0] = sieve[1] = 0;
    for (ll i = 2; i <= n; i++) {
        if (sieve[i] == 0) continue;
        
        for (ll j = i*i; j <= n; j += i) {
            if (sieve[j]) {
                sieve[j] = 0;
            }
        }
    }
}

int countPrimes(int n){
    vector<int> sieve(n+1, 1);
    primeSieve(sieve);

    // accumulative sum
    vector<int> csum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        csum[i] = csum[i - 1] + sieve[i];
    }

    return n == 0 ? 0 : csum[n - 1];
}

int main() {
    int n;
    cin >> n;
    cout << countPrimes(n) << "\n";
    return 0;
}