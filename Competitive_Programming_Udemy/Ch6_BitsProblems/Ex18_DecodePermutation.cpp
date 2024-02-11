#include <bits/stdc++.h>

using namespace std;

// vector<int> decode(vector<int> encoded) {
//     int size = encoded.size();
//     int n = size + 1;
//     set<int> used;
//     vector<int> decoded;
//     int first = 1;
//     while(decoded.size() != n){
//     	decoded.push_back(first);
//     	used.insert(first);

//     	int temp = first;
//     	for(int i=0;i<size;i++){
//     		int next = temp ^ encoded[i];

//     		// if it has used
//     		if(used.find(next) != used.end() || next > n || next <= 0){
//     			// next guess
//     			first++;
//     			used.clear();
//     			decoded.clear();
//     			break;
//     		}

//     		decoded.push_back(next);
//     		used.insert(next);
//     		temp = next;

//     	}
//     }

//     return decoded;
// }

// ans
vector<int> decode(vector<int> encoded) {
	int n = encoded.size() + 1;
	int first = 1;
	for(int i=2;i<=n;i++){
		first ^= i;
	}
	for(int i=1;i<n-1;i+=2){
		first ^= encoded[i];
	}

	vector<int>decoded;
	decoded.push_back(first);

	for(int i=0;i<n-1;i++){
		int next = decoded.back() ^ encoded[i];
		decoded.push_back(next);
	}

	return decoded;
	
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> encoded;
	int n;  // always odd, and encoded.length == n - 1
	cin >> n;
	int num;
	//encoded.length == n - 1
	int length = n-1;
	while(length--){
		cin >> num;
		encoded.push_back(num);
	}

	vector<int> decoded = decode(encoded);
	for(const int &ans:decoded){
		cout << ans << " ";
	}
	cout << endl;


	return 0;
}