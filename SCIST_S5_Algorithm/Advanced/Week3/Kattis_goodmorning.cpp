#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> table = {
	{1, 2, 4, 5, 7, 8, 0}, //0
	{1}, //1
	{1, 2}, //2
	{1, 2, 3}, //3
	{1, 4}, //4
	{1, 2, 4, 5}, //5
	{1, 2, 3, 4, 5, 6}, //6
	{1, 4, 7}, //7
	{1, 2, 4, 5, 7, 8}, //8
	{1, 2, 3, 4, 5, 6, 7, 8, 9} //9
};

bool inTable(int cur, int prev) {
	for (int num : table[cur]) {
		if (prev == num) {
			return true;
		}
	}
	
	return false;
}

bool valid(int num) {
	string s = to_string(num);
	int len = s.size();
	for (int i = 1; i < len; i++) {
		int cur = s[i] - '0';
		int prev = s[i-1] - '0';
		if (!inTable(cur, prev)) {
			return false;
		}
	}
	
	return true;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int num;
		cin >> num;
		
		int num1 = num;
		int num2 = num;
		while(!valid(num1)) {
			num1++;
		}
		while(!valid(num2)) {
			num2--;
		}
		if (num1 - num < num - num2) {
			cout << num1 << "\n";
		}
		else {
			cout << num2 << "\n";
		}
	}
	return 0;
}