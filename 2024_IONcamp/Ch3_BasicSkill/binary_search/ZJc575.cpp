#include <bits/stdc++.h>

#define int long long // the value cannot be the negative value!!!
using namespace std;

bool check(const vector<int> & vc, int k, int mid) {
    int range = vc[0] + mid;
    k--;

    for (int i = 1; i < vc.size(); i++) {
        if (vc[i] <= range) {
            continue;
        }    

        range = vc[i] + mid;
        k--;
    }

    if (k < 0) {
        return false;
    }
    else {
        return true;
    }
}

int32_t main() {
    int n, k;
    cin >> n >> k;
    vector<int> vc(n);

    for (int& x:vc) {
        cin >> x;
    }

    sort(vc.begin(), vc.end());
    int l = 1;
    int r = vc[n-1] - vc[0];

    while(l != r) {
        int mid = (l + r) / 2;
        if (check(vc, k, mid)) {
            r = mid;
        }
        else {
            l = mid + 1;
        }
    }

    cout << r << "\n";
    return 0;
}