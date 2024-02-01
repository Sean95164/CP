#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> nums) {
    priority_queue<int, vector<int>, greater<int> > pq;
    for(const int &num:nums){
    	pq.push(num);
    }
    int sum{0};
    while(pq.size() != 1){
    	int firstSmall = pq.top();
    	pq.pop();
    	int secondSmall = pq.top();
    	pq.pop();

    	int cost = firstSmall + secondSmall;
    	sum += cost;

    	pq.push(cost);
    }

    return sum;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	vector<int> vc;
	int n;
	cin >> n;

	int num;
	while(n--){
		cin >> num;
		vc.push_back(num);
	}

	cout << solve(vc) << endl;
	
	return 0;
}