#include <iostream>
#include<vector>
#include<queue>
using namespace std;

#define X first
#define Y second

int board[55][55];
int n, m;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({ i, j });
            if (board[i][j] == 2) house.push_back({ i, j });
        }
    }
    vector<int> brute(chicken.size(), 1);
    fill(brute.begin(), brute.begin() + chicken.size() - m, 0);)
    return 0;
}