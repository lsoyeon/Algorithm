#include <iostream>
#include <set>
#include <string>
using namespace std;

int cases;
char board[4][4];
set<string> results;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void explore(int row, int col, string str, int depth) {
	if (depth == 7) {
		results.insert(str);
		return;
	}
	for (int dir = 0; dir < 4; ++dir) {
		int nx = row + dx[dir];
		int ny = col + dy[dir];
		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
			explore(nx, ny, str + board[nx][ny], depth + 1);
		}
	}
}

int main() {
	cin >> cases;
	for (int tc = 1; tc <= cases; ++tc) {
		results.clear();
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				cin >> board[i][j];

		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				explore(i, j, string(1, board[i][j]), 1);

		cout << '#' << tc << ' ' << results.size() << '\n';
	}
	return 0;
}
