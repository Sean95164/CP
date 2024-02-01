#include <bits/stdc++.h>

using namespace std;

vector<int> decode(vector<int> encoded, int first) {
    vector<int> origin;
    origin.push_back(first);
    for(int i=0;i<encoded.size();i++){
    	int current = origin.back();
    	origin.push_back((current ^ encoded[i]));
    }

    return origin;
}


int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> encoded;
	int n;
	cin >> n;

	int num;
	while(n--){
		cin >> num;
		encoded.push_back(num);
	}

	int first;
	cin >> first;

	vector<int> ans = decode(encoded, first);

	for(const int &num:ans){
		cout << num << " ";
	}

	cout << endl;
	
	return 0;
}