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
	cin >> a;
	int words = 0;

	for (int i = 0; i < a.length(); i++) {
		if (a[i] == ' ') {
			words++;
		}
	}

	cout << words + 1;



	return 0;
}