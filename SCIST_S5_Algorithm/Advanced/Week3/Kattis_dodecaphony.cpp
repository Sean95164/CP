#include <bits/stdc++.h>


using namespace std;

vector<string> melody = {
	"C",  //0
	"C#", //1
	"D",  //2
	"D#", //3
	"E",  //4
	"F",  //5
	"F#", //6
	"G",  //7
	"G#", //8
	"A",  //9
	"A#", //10
	"B"   //11
};

int find_index(string s) {
	int len = melody.size();
	for (int i = 0; i < len; i++) {
		if (s == melody[i]) {
			return i;
		}
	}
	
	return -1;
}

bool transposition(const vector<string> &m1, const vector<string> &m2) {
	int shift = find_index(m2[0]) - find_index(m1[0]);
	int len = m1.size();
	for (int i = 1; i < len; i++) {
		int shift_index = (find_index(m1[i]) + shift + 12) % 12;
		if (melody[shift_index] != m2[i]) {
			return false;
		}
	}
	
	return true;
}

bool retrograde (const vector<string> &m1, const vector<string> &m2) {
	int len = m1.size();
	for (int i = 0; i < len; i++) {
		if (m1[i] != m2[len - i - 1]) {
			return false;
		}
	}
	
	return true;
}

bool inversion(const vector<string> &m1, const vector<string> &m2) {
	int first = find_index(m1[0]);
	int len = m1.size();
	for (int i = 1; i < len; i++) {
		int second = find_index(m1[i]);
		int shift = second - first;
		int next = (first - shift + 12) % 12;
		if (melody[next] != m2[i]) {
			return false;
		}
	}
	
	return true;
}

int main() {
	
	int l;
	cin >> l;
	
	vector<string> m1(l), m2(l);
	for (int i = 0; i < l; i++) {
		cin >> m1[i];
	}
	
	for (int i = 0; i < l; i++) {
		cin >> m2[i];
	}
	
	if (transposition(m1, m2)) {
		cout << "Transposition\n";
	}
	else if (retrograde(m1, m2)) {
		cout << "Retrograde\n";
	}
	else if (inversion(m1, m2)) {
		cout << "Inversion\n";
	}
	else {
		cout << "Nonsense\n";
	}
	return 0;
}












