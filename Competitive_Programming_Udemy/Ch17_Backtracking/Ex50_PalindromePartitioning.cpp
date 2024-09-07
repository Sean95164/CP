#include<bits/stdc++.h>
using namespace std;

bool check(string s) {
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return tmp == s;
}

void __partition(string s, int index, vector<string> &cur,vector<vector<string>> &ans) {
    if(index >= (int)s.size()) {
        ans.push_back(cur);
        return;
    }
    
    for (int i = index; i < (int)s.size(); i++) {
        string tmp = s.substr(index, i - index + 1);
        if (check(tmp)) {
            cur.push_back(tmp);
            __partition(s, i+1, cur, ans);
            cur.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> cur;
    __partition(s, 0, cur, ans);
    return ans;
}

int main() {
    vector<vector<string>> ans = partition("aab");
    for (auto s : ans) {
        for (auto x : s) {
            cout << x << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}