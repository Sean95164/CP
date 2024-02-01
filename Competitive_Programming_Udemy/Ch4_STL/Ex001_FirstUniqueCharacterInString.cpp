#include <bits/stdc++.h>

using namespace std;

int firstUniqChar(string s) {
	set<char> appeared;
	set<char> duplicated;

	for(const auto &cha:s){
		// not find
		if(appeared.find(cha) == appeared.end()){
			appeared.insert(cha);
		}
		else{
			duplicated.insert(cha);
		}
	}

	for(const auto &cha:s){
		// check if it appears two times
		if(duplicated.find(cha) == duplicated.end()){
			return s.find(cha);
		}
	}

	return -1;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s;
	cin >> s;	

	int ans = firstUniqChar(s);

	cout << ans << endl;
	
	return 0;
}