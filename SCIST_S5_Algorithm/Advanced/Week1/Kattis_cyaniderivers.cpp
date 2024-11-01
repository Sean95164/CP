#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	vector<int> left_pos(s.size(), INT_MAX);
	vector<int> right_pos(s.size(), INT_MAX);
	int pos = 0;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '1') {
			pos = i;
		}
		else {
			left_pos[i] = i - pos;
		}
	}
	
	pos = s.size() - 1;
	for (int i = s.size() - 2; i >= 0; i--) {
		if (s[i] == '1') {
			pos = i;
		}
		else {
			right_pos[i] = pos - i;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '0') {
			int tmp = min(left_pos[i], right_pos[i]);
			ans = max(ans, tmp);
		}
	}
	
	cout << ans << "\n";
	return 0;
}