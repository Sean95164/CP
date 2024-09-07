#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5;
string solve(int n, int k, vector<int> c){

    // create prime factorization table
    vector<int> sieve(N+1, 0);
    for (int i = 0; i <= N; i++) {
        sieve[i] = i;
    }

    for (ll i = 2; i <= N; i++) {
        if (sieve[i] == i) {
            for (ll j = i*i; j <= N; j += i) {
                if (sieve[j] == j) {
                    sieve[j] = i;
                }
            }
        }
    }

    map<int, int> count;
    for (int i = 0; i < n; i++) {
        int x = c[i];
        while(x != 1) {
            count[sieve[x]]++;
            x /= sieve[x];
        }
    }

    // check c vector factors cover all k factors
    while(k != 1) {
        if (count[sieve[k]] <= 0) {
            return "No";
        }
        count[sieve[k]]--;
        k /= sieve[k];
    }

    return "Yes";
}

int main() {
    cout << solve(4, 5, {2, 3, 5, 12}) << endl;
    return 0;
}