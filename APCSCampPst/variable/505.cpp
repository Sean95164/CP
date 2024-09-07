#include <iostream>
#include <iomanip>

using namespace std;

double tranform(int f) {
    return (5.0 / 9) * (f - 32);
}

int main() {
    int f;
    cin >> f;
    cout << setprecision(2) << fixed;
    cout << tranform(f) << endl;
    return 0;
}