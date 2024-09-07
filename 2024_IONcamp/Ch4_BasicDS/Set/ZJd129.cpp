#include <bits/stdc++.h>

using namespace std;

int main() {
    long long start = 1;

    // min heap
    priority_queue<long long, vector<long long>, greater<long long>> minH;
    // record whether found or not
    set<long long> st;

    int i = 1;
    st.insert(start);
    minH.push(start);
    int num[3] = {2, 3, 5};
    // find the 1500'th ugly number
    while(i != 1500) {
        long long x = minH.top();
        minH.pop();
        for (int j = 0; j < 3; j++) {
            if (!st.count(x*num[j])) {
                st.insert(x*num[j]);
                minH.push(x*num[j]);
            }
        }
        i++;
    }

    cout << "The 1500'th ugly number is " << minH.top() << ".\n";

    
    return 0;
}