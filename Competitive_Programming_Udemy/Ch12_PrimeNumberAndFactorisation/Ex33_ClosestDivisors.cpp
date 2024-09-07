#include <bits/stdc++.h>

using namespace std;

int findFact(int num) {
    int ans = 1;
    for (int i = 2; i*i <= num; i++) {
        if (num % i == 0) {
            ans = i;
        }
    }

    return ans;
}

vector<int> closestDivisors(int num) {
    vector<int> ans;
    int a = num + 1;
    int b = num + 2;
    int f1 = findFact(a);
    int f2 = findFact(b);

    if (abs(f1 - a / f1) <= abs(f2 - b / f2)) {
        ans.push_back(f1);
        ans.push_back(a / f1);
    }
    else {
        ans.push_back(f2);
        ans.push_back(b / f2);
    }

    return ans;
}

int main() {
    int num;
    cin >> num;
    vector<int> ans = closestDivisors(num);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}