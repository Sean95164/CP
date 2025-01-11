#include <bits/stdc++.h>

using namespace std;

int solve(const string &s, int n, int &index) {
	index++;
	int result = 0;
	if (s[index] == '1') {
		result += n * n;
	}	
	else if (s[index] == '0') {
	}
	else if (s[index] == '2') {
		for (int i = 1; i <= 4; i++) {
			result += solve(s, n / 2, index);
		}
	}
	
	return result;
}

int main() {
	string s;
	cin >> s;
	int n;
	cin >> n;

	int index = -1;
	cout << solve(s, n, index) << "\n";
	return 0;
}