#include<bits/stdc++.h>
using namespace std;

vector<long long> subsetSum(vector<long long> arr) {
    int n = arr.size();
    vector<long long> result;

    for (int i = 0; i < (1 << n); i++) {
        long long sum = 0;
        for (int j = 0; j < n; j++) {
            if ((i>>j)&1) {
                sum += arr[j];
            }
        }

        result.push_back(sum);
    }

    return result;
}

long long solve(int n,int x, vector<int> a) {
    vector<long long> left, right;

    for (int i = 0; i < n; i++) {
        if (i < n / 2) {
            left.push_back(a[i]);
        }
        else {
            right.push_back(a[i]);
        }
    }

    vector<long long> leftSums = subsetSum(left);
    vector<long long> rightSums = subsetSum(right);
    
    sort(rightSums.begin(), rightSums.end());

    long long ans = 0;
    for (auto ele : leftSums) {
        ans += upper_bound(rightSums.begin(), rightSums.end(), x - ele) - 
               lower_bound(rightSums.begin(), rightSums.end(), x - ele);
    }

    return ans;
}   

int main() {
    int n = 4;
    int x = 5;
    vector<int> arr = {1, 2, 3, 2};

    cout << solve(n, x, arr) << endl;
    return 0;
}