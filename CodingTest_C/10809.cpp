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
	 
	1. �����ؼ�
	�� ���ĺ����� �����ϸ� ���� �ε����� ��ġ��, ������ -1�� ����϶�
	
	2. ������ Ǯ��

	���ĺ� �迭, -1�� �ʱ�ȭ
	���ĺ� �Է�
	���ĺ� �ε����� ���ĺ� �迭�� �������� ������
	���� ���ĺ��� ������
	   ���ĺ��� ��ġ �ε����� �迭�� -1��� ����ֱ�
	���� ���ĺ��� ������
	   -1 �״�� �α�

	���ĺ� �迭 ���

	3. psuedo code

	����<int> ��� -1��, 26�� ����
	���ĺ� ���ڿ� �Է¹ޱ�

	for(i, ���ڿ� ����)
	  for(j, ���ĺ� �迭 ũ��)
	    if(���ڿ�[i] == ���ĺ��迭[j]) {
		   ���ĺ� �迭[j] = i
		   }

		   ���ĺ� �迭 ���
	*/
	
	string words;
	cin >> words;
	vector<int> v1(26, -1);

	for (int i = 0; i < words.length(); i++) {
		int idx = words[i] - 'a';

			
			if (v1[idx] == -1) {
				v1[idx] = i;
			}
		
		
	}

	for (int i = 0; i < 26; i++) {
		cout << v1[i] << (i == 25 ? '\n' : ' ');
	}

	



	return 0;
}