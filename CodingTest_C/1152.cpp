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
	getline(cin, a);//�� ���� ��ü�� �Է¹ޱ�
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