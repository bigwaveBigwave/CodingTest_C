#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;


//1. ���� �ؼ� : �־��� �׽�Ʈ ���� ���� ���� 1~3���� ������� �� �ִ� ����� ���� ����ϱ�
//2. ������ Ǯ��
/*
�׽�Ʈ ���̽� ���� �Է¹ޱ�
�迭 ����
�迭 �ʱ� �� ����
�׽�Ʈ���̽� for��{
�����Է¹ޱ�


}

1. ���̺� �����ϱ�
D[i] = i�� 1,2,3�� ������ ��Ÿ���� ����� ��

2. ��ȭ�� ã��
D[i] = D[i-1] + D[i-2] + D[i-3]

3. �ʱⰪ ���ϱ�
D[1] = 1
D[2] = 2
D[3] = 4

*/

int d[1000005];
int n, T;

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr);
	d[1] = 1;
	d[2] = 2;
	d[3] = 4;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		d[n] = d[n - 1] + d[n - 2] + d[n - 3];
		cout << d[n] << "\n";
	}
	
	return 0;
}