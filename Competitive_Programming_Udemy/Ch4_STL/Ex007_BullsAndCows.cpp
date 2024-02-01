#include <bits/stdc++.h>

using namespace std;

string getHint(string secret, string guess) {
	int bulls{0}, cows{0};
	map<char, int> appeared;

	for(int i=0;i<secret.length();i++){
		if(secret[i] == guess[i]){
			bulls++;
		}
		else{
			appeared[secret[i]]++;
		}
	}

	for(int i=0;i<guess.length();i++){
		if(appeared[guess[i]] != 0){
			cows++;
			appeared[guess[i]]--;
		}
	}

	return to_string(bulls) + "A" + to_string(cows) + "B";

}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string secret, guess;

	cin >> secret >> guess;

	cout << getHint(secret, guess) << endl;
	
	return 0;
}