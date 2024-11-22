#include <bits/stdc++.h>

using namespace std;

string month[] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

int string_to_month(const string &s) {
	for (int i = 1; i <= 12; i++) {
		if (s == month[i]) {
			return i;
		}
	}
	
	return -1;
}

const int DAY[] = {120, 219, 320, 420, 
				   520, 621, 722, 822, 
                   921, 1022, 1122, 1221, 9999};
                   
const string NAM[] = {"Capricorn", "Aquarius", "Pisces", "Aries", 
					  "Taurus", "Gemini", "Cancer", "Leo", 
                      "Virgo", "Libra", "Scorpio", "Sagittarius", "Capricorn"};

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int d;
		string m;
		cin >> d >> m;
		int res = d + 100 * string_to_month(m);
		
		int ans = 0;
		for (;res > DAY[ans]; ans++);
		
		cout << NAM[ans] << "\n";
	}
	return 0;
}