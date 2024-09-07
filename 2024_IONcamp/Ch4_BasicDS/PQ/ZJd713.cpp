#include <bits/stdc++.h>

using namespace std;

int main() {
    // min heap
    priority_queue<int, vector<int>, greater<int>> minH; 
    // max heap
    priority_queue<int> maxH;

    int x;
    while(cin >> x) {
        if (maxH.empty() || maxH.top() > x) {
            maxH.push(x);
        }
        else {
            minH.push(x);
        }
        
        if (maxH.size() > minH.size() + 1) {
            minH.push(maxH.top());
            maxH.pop();
        }
        else if (minH.size() > maxH.size() + 1) {
            maxH.push(minH.top());
            minH.pop();
        }

        if (maxH.size() == minH.size()) {
            cout << (maxH.top() + minH.top()) / 2 << "\n"; 
        }
        else if (maxH.size() > minH.size()) {
            cout << maxH.top() << "\n";
        }
        else {
            cout << minH.top() << "\n";
        }

    }
    
    return 0;
}