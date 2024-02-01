#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    int cntMax = 0;

   	int cntCurrent = 0;
   	while(n>0){
   		if(n & 1){
   			cntCurrent++;
   		}
   		else{
   			cntMax = max(cntMax, cntCurrent);
   			cntCurrent = 0;
   		}

   		n>>=1;
   	}

   	cntMax = max(cntMax, cntCurrent);
   	return cntMax;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	cout << solve(n) << endl;
	
	return 0;
}