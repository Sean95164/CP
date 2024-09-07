#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll op(vector<int> a, vector<int> b, int num) {
    ll cnt = 0;
    for (auto ele : a) {
        if (ele > num) {
            break;
        }
        cnt += abs(num - ele);
    }

    for (int j = b.size() - 1; j >= 0; j--) {
        if (b[j] < num) {
            break;
        }
        cnt += abs(b[j] - num);
    }

    return cnt;
}

long long solve(int n,int m,vector<int> a,vector<int> b){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l = 1;
    int r = 1e9;

    ll ans = 1e18;

    while(l <= r) {
        int mid1 = l+(r-l)/3;
        int mid2 = r-(r-l)/3;
        ll x = op(a, b, mid1);
        ll y = op(a, b, mid2);
        
        if (x < y) {
            r = mid2 - 1;
        }
        else if (x > y) {
            l = mid1 + 1;
        }
        else {
            ans = min(ans, x);
            l = mid1 + 1;
            r = mid2 - 1;
        }
        
    }

    return ans;
}

int main() {
    int n = 2;
    int m = 2;
    vector<int> a = {2, 3};
    vector<int> b = {3, 5};
    cout << solve(n, m, a, b) << endl; // 3
    // cout << solve(2, 2, {50, 50}, {3, 100}) << endl;  

    return 0;
}