#include<iostream>
#include<stack>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
	1. ���� �ؼ�
	���ڸ� ���� �ΰ� �־�����(0�� ���Ծȵ�) �� ���� �ڿ������� �о �� �� ū �������ϱ�

	2. ������ Ǯ��
	�� ���� ���ڿ��� ���� �ΰ��� �Է� �ޱ�

	�� ���� ���� �Ųٷ� �ϱ�


	�ִ� ���ϱ�


	3. psuedo coding
	�ִ�, ����1, ��1, ����2, ��2 ����
	���ڿ��� �Է¹ޱ�. 2�� ����.
	for(3��) {
	string1_r[i] = string1[2-i]
	string2_r[i] = string2[2-i]
	}

	if(int(string1_r) > int(string2_r)
	cout << 1
	}
	else {
	cout << 2
	*/

	int max = -1;
	string s1, s1_r, s2, s2_r;

	cin >> s1;
	s1_r = s1;

	cin >> s2;
	s2_r = s2;

	for (int i = 0; i < 3; i++) {
		s1_r[i] = s1[2 - i];
		s2_r[i] = s2[2 - i];
	}

	if (stoi(s1_r) > stoi(s2_r)) {
		cout << s1_r;
	}
	else {
		cout << s2_r;
	}





	return 0;
}