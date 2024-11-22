#include <bits/stdc++.h>

using namespace std;

int main() {
	int round = 1;
	string s;
	getline(cin, s);
	
	for (char c : s) {
		if (c == ' ') {
			round++;
		}
	}
	
	int n;
	cin >> n;
	
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	vector<string> t1;
	vector<string> t2;
	
	bool turn_t1 = true;
	int pos = 0;
	while(!arr.empty()) {
		pos = (pos - 1 + round) % arr.size();
		if (turn_t1) {
			t1.push_back(arr[pos]);
		}
		else {
			t2.push_back(arr[pos]);
		}
		
		arr.erase(arr.begin() + pos);
		turn_t1 = !turn_t1;
	}
	
	cout << t1.size() << "\n";
	for (string s : t1) {
		cout << s << "\n";
	}
	
	cout << t2.size() << "\n";
	for (string s : t2) {
		cout << s << "\n";
	}
	

	return 0;
}