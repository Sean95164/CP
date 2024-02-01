#include <bits/stdc++.h>

using namespace std;

int count_bits_hack(int n){
	int cnt = 0;
	while(n>0){
		n = n & (n-1);
		cnt++;
	}

	return cnt;
}

vector<int> sortByBits(vector<int> arr) {
	auto cmp = [](int a, int b){
		int bitsA = count_bits_hack(a);
		int bitsB = count_bits_hack(b);

		if(bitsA != bitsB)
			return count_bits_hack(a) < count_bits_hack(b);
		else
			return a < b;
	};

	
    sort(arr.begin(), arr.end(), cmp);

    return arr;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr;
	int n;
	cin >> n;

	int num;
	while(n--){
		cin >> num;
		arr.push_back(num);
	}

	vector<int> ans = sortByBits(arr);
	for(const int &num:ans){
		cout << num << " ";
	}

	cout << endl;
	
	return 0;
}