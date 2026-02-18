#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a%b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pre_gcd(n+1);
    vector<int> suf_gcd(n+1);
    for (int i = 0; i < n; i++) {
        pre_gcd[i+1] = gcd(pre_gcd[i], a[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        suf_gcd[i] = gcd(suf_gcd[i+1], a[i]);
        // cout << suf_gcd[i] << "\n";
    }
    
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, gcd(pre_gcd[i], suf_gcd[i+1]));
    }
    cout << maxi << "\n";
    return 0;
}