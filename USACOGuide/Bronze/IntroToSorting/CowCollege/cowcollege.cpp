#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<long long> c(n);
    set<long long> distinct;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        distinct.insert(c[i]);
    }

    sort(c.begin(), c.end());
    long long total_maxi = 0, maxi = 0;
    for (long long num : distinct) {
        int students = c.size() - (lower_bound(c.begin(), c.end(), num) - c.begin());
        if (students * num > total_maxi) {
            total_maxi = students * num;
            maxi = num;
        }
    }
    cout << total_maxi << " " << maxi << "\n";
    return 0;
}