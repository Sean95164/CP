#include <bits/stdc++.h>

using namespace std;

string solve(int a, int b, int c) {
    if ((c & 1) == 0) {
        a = abs(a);
        b = abs(b);
        if (a < b) return "<";
        else if (a > b) return ">";
        else return "=";
    }
    else {
        if (a < b) return "<";
        else if (a > b) return ">";
        else return "=";
    }
    
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    string result = solve(a, b, c);
    cout << result << endl;

    return 0;
}