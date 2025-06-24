#include <iostream>
#include <queue>
using namespace std;

int M, N, H;
int board[100][100][100];
int dz[6] = { -1, 1, 0, 0, 0, 0 };
int dy[6] = { 0, 0, -1, 1, 0, 0 };
int dx[6] = { 0, 0, 0, 0, -1, 1 };

struct Point {
    int z, y, x;
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> M >> N >> H;

    queue<Point> q;
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                cin >> board[h][n][m];
                if (board[h][n][m] == 1) {
                    q.push({ h, n, m }); // 익은 토마토 시작점
                }
            }
        }
    }

    while (!q.empty()) {
        Point cur = q.front(); q.pop();
        for (int dir = 0; dir < 6; dir++) {
            int nz = cur.z + dz[dir];
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            if (nz < 0 || ny < 0 || nx < 0 || nz >= H || ny >= N || nx >= M)
                continue;
            if (board[nz][ny][nx] == 0) {
                board[nz][ny][nx] = board[cur.z][cur.y][cur.x] + 1;
                q.push({ nz, ny, nx });
            }
        }
    }

    int answer = 0;
    for (int h = 0; h < H; h++) {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (board[h][n][m] == 0) {
                    cout << -1;
                    return 0;
                }
                answer = max(answer, board[h][n][m]);
            }
        }
    }

    cout << answer - 1 << '\n'; 
}
