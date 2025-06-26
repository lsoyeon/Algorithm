#include <tuple>
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m, k;
int map[1001][1001];
bool check[1001][1001][11];
int dist[1001][1001][11];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int bfs() {
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    check[0][0][0] = true;
    dist[0][0][0] = 1;

    while (!q.empty()) {
        auto [y, x, broken] = q.front(); q.pop();

        if (y == n - 1 && x == m - 1) return dist[y][x][broken];

        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            //범위 벗어나는 경우
            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            //벽 부수지 않는 경우
            if (map[ny][nx] == 0 && !check[ny][nx][broken]) {
                check[ny][nx][broken] = true;
                dist[ny][nx][broken] = dist[y][x][broken] + 1;
                q.push({ny, nx, broken});
            }
            //벽 부수는 경우
            else if (map[ny][nx] == 1 && broken < k && !check[ny][nx][broken + 1]) {
                check[ny][nx][broken + 1] = true;
                dist[ny][nx][broken + 1] = dist[y][x][broken] + 1;
                q.push({ny, nx, broken + 1});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); 
    cout.tie(0);

    cin >> n >> m >> k;
    // 빈칸없이 입력 받을 때 - string으로 한 줄씩 받고, 나눠서 저장
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < m; ++j) {
            map[i][j] = s[j] - '0'; //char을 int로 바꾸기
        }
    }

    cout << bfs() << "\n";
    return 0;
}
