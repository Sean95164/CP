#include <bits/stdc++.h>

using namespace std;

int main() {
	map<char, string> table;
	
	table['a'] = "2";
	table['b'] = "22";
	table['c'] = "222";
	table['d'] = "3";
	table['e'] = "33";
	table['f'] = "333";
	table['g'] = "4";
	table['h'] = "44";
	table['i'] = "444";
	table['j'] = "5";
	table['k'] = "55";
	table['l'] = "555";
	table['m'] = "6";
	table['n'] = "66";
	table['o'] = "666";
	table['p'] = "7";
	table['q'] = "77";
	table['r'] = "777";
	table['s'] = "7777";
	table['t'] = "8";
	table['u'] = "88";
	table['v'] = "888";
	table['w'] = "9";
	table['x'] = "99";
	table['y'] = "999";
	table['z'] = "9999";
	table[' '] = "0";

	int n;
	cin >> n;
	cin.ignore();
	int c = 1;
	while(n--) {
		string s;
		cout << "Case #" << c << ": ";
		getline(cin, s);
		
		string ans = "";
		for (char ch : s) {		
			string q = table[ch];
			if (q[0] == ans.back()) {
				ans += " ";
			}
			ans += q;
		}
		cout << ans << "\n";
		c++;
	}
	return 0;
}



















