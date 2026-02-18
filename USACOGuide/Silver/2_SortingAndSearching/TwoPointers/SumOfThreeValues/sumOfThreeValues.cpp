#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Number
{
    long long value;
    int index;
};

int main() {
    int n;
    long long x;
    cin >> n >> x;

    vector<Number> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i].value;
        nums[i].index = i + 1;
    } 

    sort(nums.begin(), nums.end(), [](const Number &n1, const Number &n2) {
        return n1.value < n2.value;
    });

    for (int i = 0; i < n; i++) {
        long long target = x - nums[i].value;
        int left = 0, right = n - 1;
        while(left != right) {
            long long sum = nums[left].value + nums[right].value;
            if (left != i && right != i && sum == target) {
                cout << nums[left].index << " " << nums[i].index << " " << nums[right].index;
                return 0;
            }

            if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}