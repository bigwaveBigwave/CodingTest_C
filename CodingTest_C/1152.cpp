#include<iostream>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string a;
	getline(cin, a);//한 줄의 전체를 입력받기
	bool inWord = false;
	int words = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] != ' ') {
			if (!inWord) {
				words++;
				inWord = true;
			}
		}
		else {
			inWord = false;
		}
	
	}

	cout << words;



	return 0;
}