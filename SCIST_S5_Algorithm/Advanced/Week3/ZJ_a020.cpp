#include <bits/stdc++.h>

using namespace std;
			   //0123456789012345678901234567890123456789 
string to_num = "          ABCDEFGHJKLMNPQRSTUVXYWZIO";

int find_index(char c) {
	int len = to_num.size();
	for (int i = 0 ; i < len; i++) {
		if (to_num[i] == c) {
			return i;
		}
	}
	return -1;
}

int main() {
	string s;
	cin >> s;
	
	// step 1:
	int num1 = find_index(s[0]);
	
	// step 2:
	num1 = (num1 % 10) * 9 + num1 / 10;
	// step 3:
	int sum = 0;
	int len = s.size();
	int times = 1;
	for (int i = len - 2; i >= 1; i--) {
		sum += times * (s[i] - '0');
		times++;
	}
	
	// step 4:
	sum = sum + num1 + (s[len - 1] - '0');

	// step 5:
	if (sum % 10 == 0) {
		cout << "real\n";
	}
	else {
		cout << "fake\n";
	}
	return 0;
}