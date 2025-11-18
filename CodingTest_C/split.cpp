#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>

using namespace std;

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