#include <iostream>

using namespace std;

int main() {
    int a;
    int m;
    cin >> a >> m;

    cout << (a % m + m) % m << endl;
    return 0;
}