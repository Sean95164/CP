#include <bits/stdc++.h>

using namespace std;

int distributeCandies(vector<int> candies) {
   	int maxNumber = candies.size() / 2;
   	set<int> distinct;

   	for(const int &type:candies){
   		distinct.insert(type);
   	}
   	
   	if(maxNumber >= distinct.size()){
   		return distinct.size();
   	}
   	else
   		return maxNumber;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> vc;
	int n;
	cin >> n;

	int type;
	while(n--){
		cin >> type;
		vc.push_back(type);
	}
	
	cout << distributeCandies(vc) << endl;
	return 0;
}