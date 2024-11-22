#include <bits/stdc++.h>

using namespace std;

char to_upper(char c) {
	return c - ('a' - 'A');
}

int main() {
	map<string, char> t;
	t["clank"] = 'a';
	t["bong"] = 'b';
	t["click"] = 'c';
	t["tap"] = 'd';
	t["poing"] = 'e';
	t["clonk"] = 'f';
	t["clack"] = 'g';
	t["ping"] = 'h';
	t["tip"] = 'i';
	t["cloing"] = 'j';
	t["tic"] = 'k';
	t["cling"] = 'l';
	t["bing"] = 'm';
	t["pong"] = 'n';
	t["clang"] = 'o';
	t["pang"] = 'p';
	t["clong"] = 'q';
	t["tac"] = 'r';
	t["boing"] = 's';
	t["boink"] = 't';
	t["cloink"] = 'u';
	t["rattle"] = 'v';
	t["clock"] = 'w';
	t["toc"] = 'x';
	t["clink"] = 'y';
	t["tuc"] = 'z';

	bool caps = false;
	
	int n;
	cin >> n;
	string in;
	vector<char> print;
	
	for (int i = 0; i < n; i++) {
		cin >> in;
		
		if (in == "whack") {
			print.push_back(' ');
		}
		else if (in == "bump" || in == "dink" || in == "thumb") {
			caps = !caps;
		}
		else if (in == "pop") {
			if (!print.empty()) {
				print.pop_back();
			}
			
		}
		else {
			char cha = t[in];
			if (caps) {
				print.push_back(to_upper(cha));
			} else {
				print.push_back(cha);
			}
		}

	}

	int len = print.size();
	for (int i = 0; i < len; i++) {
		if (i == len - 1) {
			cout << print[i] << "\n";
		}
		else {
			cout << print[i];
		}
	}
	return 0;
}