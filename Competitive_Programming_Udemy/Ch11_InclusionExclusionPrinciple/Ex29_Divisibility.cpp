#include <bits/stdc++.h>

using namespace std;

int numDivisible(int l,int r, vector<int> arr){
    int n = arr.size();
    l -= 1;

    int ans_r = 0;
    int ans_l = 0;
    for (int i = 1; i < (1 << n); i++) {
        long long lcm = 1;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if ((i>>j) & 1) {
                // find least common multiple
                lcm = (lcm*(long long)arr[j]) / __gcd(lcm, (long long)arr[j]);
                cnt++;
            }

            if (lcm > r) break;
        }

        if(lcm > r) continue;
        if (cnt % 2 == 0) {
            ans_r -= r / lcm;
            ans_l -= l / lcm;
        }
        else {
            ans_r += r / lcm;
            ans_l += l / lcm;
        }
    }

    return ans_r - ans_l;
}

int main() {
    int l = 579000;
    int r = 987654;
    vector<int> arr = {1, 2};

    cout << numDivisible(l, r, arr) << "\n";
    return 0;
}