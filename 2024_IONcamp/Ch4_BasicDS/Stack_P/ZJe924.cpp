#include <bits/stdc++.h>

using namespace std;

bool check(const string & s) {
    stack<char> stk;
    for (auto & c:s) {
        if (c == '(' || c == '[' || c == '<' || c == '{') {
            stk.push(c);
        }
        else {
            if (stk.empty()) return false;
            const char top = stk.top();
            stk.pop();
            if ((top == '(' && c != ')') || (top == '[' && c != ']') ||
                (top == '<' && c != '>') || (top == '{' && c != '}')) {
                    return false;
                }
        }
    }

    return stk.empty();
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    string s;
    while(t--) {
        getline(cin, s);
        if (check(s)) {
            cout << "Y" << endl;
        }
        else {
            cout << "N" << endl;
        }
    }

    return 0;
}