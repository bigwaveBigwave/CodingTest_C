#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> words(5);
	int max_len = 0;
	
	//5줄 입력 받기
	for (int i = 0; i < 5; i++) {
		cin >> words[i];
		if (words[i].length() > max_len) {
			max_len = words[i].length();
		}
	}


	// 세로로 읽기
	for (int col = 0; col < max_len; col++) {
		for (int row = 0; row < 5; row++) {
			if (col < words[row].size()) {
				cout << words[row][col];
			}
		}
		
	}




	



	return 0;
}