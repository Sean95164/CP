#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
	int t;
	cin >> t;
	while(t--) {
		int c, e;
		cin >> c >> e;
		
		vector<int> cs(c);
		vector<int> es(e);
		
		int sum_c = 0;
		for (int i = 0; i < c; i++) {
			cin >> cs[i];
			sum_c += cs[i];
		}
		
		double ave_c = sum_c * 1.0 / c;
		
		int sum_e = 0;
		for (int i = 0; i < e; i++) {
			cin >> es[i];
			sum_e += es[i];
		}
		
		double ave_e = sum_e * 1.0 / e;
		
		sort(cs.begin(), cs.end());
		
		int ans = 0;
		for (int i = 0; cs[i] < ave_c; i++) {
			if (cs[i] > ave_e) {
				ans++;
			}
		}
		
		cout << ans << "\n";
	}
	return 0;
}