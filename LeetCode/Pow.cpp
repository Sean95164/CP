#include <bits/stdc++.h>

using namespace std;

double myPowHelper(double x, long long n) {
    if (x == 0 || x == 1) {
        return x;
    }
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 1 / myPowHelper(x, -n);
    }
    else {
        double tmp = myPowHelper(x, n / 2);
        if (n&1) {
            return x * tmp * tmp;
        }
        else {
            return tmp * tmp;
        }
    }
}

double myPow(double x, int n) {
    return myPowHelper(x, static_cast<long long>(n));
}

int main() {
    double x;
    int n;
    cin >> x >> n;

    cout << myPow(x, n) << endl;
    return 0;
}