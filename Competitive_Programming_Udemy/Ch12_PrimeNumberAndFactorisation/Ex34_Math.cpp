#include <bits/stdc++.h>
using namespace std;

int power(int x, int y) {
    if (y == 0) return 1;
    if (y % 2 == 1) {
        return x * power(x, y - 1);
    }
    int tmp = power(x, y / 2);
    return tmp*tmp;
}

vector<int> solve(int n) {
    vector<int> sieve(n+1);
    for (int i = 0; i <= n; i++) {
        sieve[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        if (sieve[i] == i) {
            for (int j = i*i; j <= n; j += i) {
                if (sieve[j] == j) {
                    sieve[j] = i;
                }
            }
        }
    }

    map<int, int> count;
    while(n != 1) {
        count[sieve[n]]++;
        n = n / sieve[n];
    }

    int minV = 1;
    int max_sqrt = 0;
    for (auto p : count) {
        minV *= p.first;
        while(power(2, max_sqrt) < p.second) {
            max_sqrt++;
        }
    }

    vector<int> ans;
    ans.push_back(minV);
    if (max_sqrt == 0) {
        ans.push_back(0);
    }
    else {
        ans.push_back(max_sqrt + 1);
    }
    return ans;
}

int main() {
    int n = 5184;
    vector<int> ans = solve(n);
    
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}