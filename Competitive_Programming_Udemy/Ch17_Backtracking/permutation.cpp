#include <bits/stdc++.h>

using namespace std;

void helper(string s, int index, vector<string> &ans) {
    if (index == s.size()) {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        helper(s, index + 1, ans);
        swap(s[index], s[i]);
    }

    return;
}

vector<string> solve(string s) {
    vector<string> ans;
    helper(s, 0, ans);
    return ans;
}

int main() {
    string s = "abc";
    vector<string> ans = solve(s);
    for (auto x: ans) {
        cout << x << endl;
    }

    return 0;
}