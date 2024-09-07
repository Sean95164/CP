#include<bits/stdc++.h>
using namespace std;

long long intersec(int n, vector<int> &arr, int s, int e) {
    //left: [s, mid], right:[mid+1, e]
    int i = s;
    int mid = (s + e) / 2;
    int j = mid + 1;

    long long cnt = 0;
    vector<int> tmp;
    while(i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            tmp.push_back(arr[i++]);
        }
        else {
            tmp.push_back(arr[j++]);
            cnt += mid - i + 1;
        }
    }

    while(i <= mid) {
        tmp.push_back(arr[i++]);
    }
    while(j <= e) {
        tmp.push_back(arr[j++]);
    }

    //copy
    int k = 0;
    for (int idx = s; idx <= e; idx++) {
        arr[idx] = tmp[k++];
    }

    return cnt;
}

long long __solve(int n, vector<int> &arr, int s, int e) {
    if (s >= e) {
        return 0;
    }

    int mid = (s + e) / 2;
    long long c1 = __solve(n, arr, s, mid);
    long long c2 = __solve(n, arr, mid + 1, e);
    long long CI = intersec(n, arr, s, e);
    return c1 + c2 + CI;
} 

long long solve(int n, vector<int> arr){
    return __solve(n, arr, 0, n - 1);
}

int main() {
    int n = 5;
    vector<int> arr = {4, 5, 6, 7, 1};
    cout << solve(5, arr) << endl;
    return 0;
}