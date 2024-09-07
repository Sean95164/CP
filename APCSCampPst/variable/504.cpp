#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double PI = 3.14159265;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int ans1 = (a + b * c) % d;
    double ans2 = (double)a / b + (double)c / d;
    double ans3 = sin((a - b)*PI / 180.0) * cos((c - d)*PI / 180.0);
    double ans4 = sqrt((double)abs(a*b-c*d));
    double ans5 = log10((double)a*b*c*d);

    cout << setprecision(6) << fixed;
    cout << ans1 << endl;
    cout << ans2 << endl;
    cout << ans3 << endl;
    cout << ans4 << endl;
    cout << ans5 << endl;
    return 0;
}