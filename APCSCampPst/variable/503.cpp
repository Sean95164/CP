#include <iostream>
#include <iomanip>

using namespace std;
const double PI = 3.1415;

int main() {
    int r;
    cin >> r;
    double ans = 2 * PI * r;
    cout << setprecision(2) << fixed << ans << endl;
    return 0;
}