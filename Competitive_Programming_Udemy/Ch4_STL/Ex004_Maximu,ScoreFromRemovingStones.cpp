#include <bits/stdc++.h>

using namespace std;

int maximumScore(int a, int b, int c) {
	priority_queue<int> pq;
	pq.push(a);
	pq.push(b);
	pq.push(c);

	int sum = 0;
	while(pq.size() >= 2){
		int firstBig = pq.top();
		pq.pop();
		int secondBig = pq.top();
		pq.pop();

		if(--firstBig != 0) pq.push(firstBig);
		if(--secondBig != 0) pq.push(secondBig);

		sum++;
	}

	return sum;

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a,b,c;
	cin >> a >> b >> c;
	cout << maximumScore(a,b,c) << endl;
	
	return 0;
}