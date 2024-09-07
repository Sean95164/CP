#include <iostream>
#include <vector>

using namespace std;
void multiply(vector<int> &ans, int num, int &size) {
    int carry = 0;
    for (int i = 0; i < size; i++) {
        int tmp = ans[i] * num + carry;
        ans[i] = tmp % 10;
        carry = tmp / 10;
    }

    // put the remaining carry to the last
    while (carry) {
        ans[size] = carry % 10;
        carry /= 10;
        size++;
    }
}
void factorial(int n) {
    // array to store large integer
    vector<int> ans(1000, 0);

    // put 1 in the first position in ans;
    ans[0] = 1;
    int size = 1;

    // multiply the number 2 to n (inclusive) one by one 
    for (int i = 2;  i <= n; i++) {
        multiply(ans, i, size);
    }

    // print the ans, using reversing order
    for (int i = size - 1; i >= 0; i--) {
        cout << ans[i];
    }

    cout << endl;
}
int main() {
    int n;
    cin >> n;
    factorial(n);

    return 0;
}