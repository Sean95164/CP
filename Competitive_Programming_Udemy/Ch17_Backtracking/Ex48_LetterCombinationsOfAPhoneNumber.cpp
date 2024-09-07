#include<bits/stdc++.h>
using namespace std;

map<char, string> m = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"},
};

void helper(string digits, int n, string s, vector<string> &ans) {
    int index = s.size();
    if (index == n) {
        ans.push_back(s);
        return;
    }

    string choose = m[digits[index]];
    for (int i = 0; i < choose.size(); i++) {
        s.push_back(choose[i]);
        helper(digits, n, s, ans);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    int n = digits.size();

    vector<string> ans;
    if (n == 0) {
        return ans;
    }

    helper(digits, n, "", ans);
    return ans;  
}

int main() {
    vector<string> ans = letterCombinations("23");
    for (auto x : ans) {
        cout << x << endl;
    }
    return 0;
}