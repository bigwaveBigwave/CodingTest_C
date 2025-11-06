#include<iostream>
#include<algorithm>
using namespace std;

//문제 해석하기
//CCTV의 종류에 따라 감시 배열이 #이 되면, #이 아닌 구역의 0의 개수 중 최솟값을 구하기

//손으로 풀기
/*
행,열 입력받기
board 배열 입력받기
감시 배열 선언하고
1,2,3,4,5 종류 별로 감시배열 채우기
감시배열에서 0인 구역을 BFS로 찾아가지고 count해서 최소 구역 출력하기


*/


//수도코딩
//

int board[502][502];
int vis[502][502];
int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			vis[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) {
				for (int k = 0; k < j; k++) {
					vis[i][k] = 100;
					if (vis[i][k] == 6) {
						break;
					}
				}
			}
			else if (board[i][j] == 2) {

			}
		}
	}

	return 0;
}