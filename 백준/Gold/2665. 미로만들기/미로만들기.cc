#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int board[52][52];
int wall[52][52];
int sz;
int mx[] = {-1, 1, 0, 0};
int my[] = {0, 0, -1, 1};

void solve() {
	queue<pair<int, int>> q;
	q.push({0, 0});
	wall[0][0] = 0;

	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();

		for (int dir = 0; dir < 4; ++dir) {
			int nx = x + mx[dir];
			int ny = y + my[dir];

			if (nx < 0 || ny < 0 || nx >= sz || ny >= sz) continue;

			if (board[ny][nx]) {
				if (wall[ny][nx] > wall[y][x]) {
					wall[ny][nx] = wall[y][x];
					q.push({nx, ny});
				}
			} else {
				if (wall[ny][nx] > wall[y][x] + 1) {
					wall[ny][nx] = wall[y][x] + 1;
					q.push({nx, ny});
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> sz;
	for (int i = 0; i < sz; ++i) {
		string line;
		cin >> line;
		for (int j = 0; j < sz; ++j) {
			board[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < sz; ++i)
		for (int j = 0; j < sz; ++j)
			wall[i][j] = INT_MAX;

	solve();
	cout << wall[sz - 1][sz - 1] << '\n';
	return 0;
}
