#include <bits/stdc++.h>

using namespace std;

void updateSum(vector<int> &sumArr, int num){
	for(int i=0;i<32;i++){
		if(num & (1<<i)){
			sumArr[i]++;
		}
	}
}

int convertFromBits(const vector<int> sumArr){
	int result = 0;
	for(int i=0;i<32;i++){
		result += (sumArr[i] * (1<<i));
	}

	return result;
}

int UniqueNumber(vector<int> arr){
	vector<int> sumArr(32,0);

	for(const int &num:arr){
		updateSum(sumArr, num);
	}

	for(int &x:sumArr){
		x %= 3;
	}

	return convertFromBits(sumArr);
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> vc = {1,2,3,1,2,3,1,2,3,10}; // 10

	cout << UniqueNumber(vc) << endl;	
	
	return 0;
}