#include <iostream>
#include <iomanip>

using namespace std;


const double PI = 3.141592654;

int main() {
    int r;
    cin >> r;
    cout << setprecision(9) << fixed;
    cout << PI * r * r << endl;
    return 0;
}