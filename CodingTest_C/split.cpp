#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;

vector<string> split(string& s, string& sep) {
	vector<string> ret;
	int pos = 0;
	while (pos < s.size()) {
		int nxt_pos = s.find(sep, pos);
		if (nxt_pos == -1) nxt_pos = s.size();
		if (nxt_pos - pos > 0)
			ret.push_back(s.substr(pos, nxt_pos - pos));
		pos = nxt_pos + sep.size();
	}
}

int main() {
	string s1 = "welcome to the black parade";
	string sep1 = " ";
	vector<string> chunks1 = split(s1, sep1);
	for (auto chunk : chunks1) cout << chunk << '/';
	string s2 = "b*!*ac*!**!*e*!*y*!*";
	string sep2 = "*!*";
	vector<string> chunks2 = split(s2, sep2);
	for (auto chunk : chunks2) cout << chunk << '/';
	return 0;
}