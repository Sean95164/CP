#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int> vc) {
    vector<int> ans;
    stack<int> stk;

    for (size_t i = 0; i < vc.size(); i++) {
        while(!stk.empty() && vc[i] >= vc[stk.top()]) {
            stk.pop();
        }
        if (stk.empty()) {
            ans.push_back(i);
        }
        else {
            ans.push_back(i - stk.top());
        }
        stk.push(i);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> vc(n);
    for (int &x:vc) {
        cin >> x;
    }
    
    vector<int> ans = solve(vc);
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }
    return 0;
}