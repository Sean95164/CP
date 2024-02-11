#include <bits/stdc++.h>

using namespace std;

int charToDigit(char c){
	return c - '0';
}

char digitToChar(int d){
	return d + '0';
}

string addNumbers(string n1, string n2){

	// First, insure the n2 to the bigger number
	if(n1.length() > n2.length()){
		swap(n1, n2);
	}

	// Reverse n1 and n2
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	string result = "";
	int carry = 0;

	for(int i=0;i<n1.length();i++){
		int digit1 = charToDigit(n1[i]);
		int digit2 = charToDigit(n2[i]);

		int sum = digit1 + digit2 + carry;
		int output_digit = sum % 10;

		carry = sum/10;
		result.push_back(digitToChar(output_digit));

	}

	// n1 has no digit, and remaining is n2
	for(int i=n1.length();i<n2.length();i++){
		int sum = charToDigit(n2[i]) + carry;

		int output_digit = sum % 10;

		carry = sum/10;
		result.push_back(digitToChar(output_digit));
	}

	// check whether carry has remaining digit
	if(carry){
		result.push_back('1');
	}


	// reverse the result
	reverse(result.begin(), result.end());

	return result;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// String 
	string s1, s2;
	cin >> s1 >> s2;

	string result = addNumbers(s1, s2);

	cout << result << endl;
	
	return 0;
}