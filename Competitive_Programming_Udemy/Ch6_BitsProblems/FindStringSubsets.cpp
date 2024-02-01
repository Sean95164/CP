#include <bits/stdc++.h>

using namespace std;

void overLayNumber(string s, int num){
	int j=0;
	while(num > 0){
		if(num & 1){
			cout << s[j];
		}
		num >>= 1;
		j++;
	}
	cout << endl;
	return;
}

void FindAllSubsets(string s){
	size_t n = s.length();
	for(int i=0; i < (1<<n);i++){
		overLayNumber(s, i);
	}
	return;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;
	FindAllSubsets(s);
	
	return 0;
}