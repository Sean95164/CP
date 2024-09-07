#include <iostream>

using namespace std;

long long power(int a, int n) {
    if (n == 0) {
        return 1;
    }

    long long tmp = power(a, n / 2);
    if (n % 2 == 1) {
        return a * tmp * tmp;
    }
    
    return tmp * tmp;
}

int main() {
    int a, n;
    cin >> a >> n;
    cout << power(a, n) << endl;;

    return 0;
}