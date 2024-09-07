#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    deque<int> d;
    while(x != 0) {
        d.push_back(x % 10);
        x /= 10;
    }

    while(d.size() > 1) {
        if (d.front() != d.back()) {
            return false;
        }

        d.pop_front();
        d.pop_back();
    }

    return true;
}

int main() {
    int x;
    cin >> x;
    cout << isPalindrome(x) << endl;
    return 0;
}