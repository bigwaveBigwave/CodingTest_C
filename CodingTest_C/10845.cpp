#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<iomanip>
#include<string>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	string command;
	queue<int> q;

	while (N--) {
		cin >> command;
		if (command == "push") {
			int K;
			cin >> K;
			q.push(K);
			cout << q.front() << " ";

		}
		else if (command == "pop") {
			if (q.empty() != 1) {
				cout << q.front() << " ";
				q.pop();
				
			}
			cout << "비어있음" << " ";
		}
		else if (command == "size") {
			cout << q.size() << " ";
		}
		else if (command == "empty") {
			if (q.empty() != 1) {
				cout << "0"<< " ";

			}
			cout << "1" << " ";
		}
		else if (command == "front") {
			if (q.empty() != 1) {
				cout << q.front() << " ";

			}
			cout << "-1" << " ";
		}
		else if (command == "back") {
			if (q.empty() != 1) {
				cout << q.back() << " ";

			}
			cout << "-1" << " ";
		}

	}

	





	return 0;
}