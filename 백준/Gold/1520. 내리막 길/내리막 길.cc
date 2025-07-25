#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define Nmax 501
#define INF 987654321
using namespace std;
int arr[Nmax][Nmax];
bool vt[Nmax][Nmax];
bool isq[Nmax][Nmax];
int dy[] = { 1, -1, 0, 0 };
int dx[] = { 0, 0, 1, -1 };
int M, N,cnt;
int dp[Nmax][Nmax];
typedef struct node {
	int y, x, h;
}node;
struct cmp {
	bool operator()(node n1, node n2) {
		return n1.h < n2.h;
	}
};
int main() {
	//freopen("input.txt", "r", stdin);
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	priority_queue<node,vector<node>, cmp> q;
	q.push({ 0, 0, arr[0][0] });
	isq[0][0] = true;
	dp[0][0] = 1;
	while (!q.empty()) {
		int cury = q.top().y;
		int curx = q.top().x;
		int curh = q.top().h;
		q.pop();
		//cout << cury << "," << curx << ": " << curh << endl;
		//vt[cury][curx] = true;
		for (int i = 0; i < 4; i++) {
			int ny = cury + dy[i];
			int nx = curx + dx[i];
			if (ny > M - 1 || nx > N - 1 || ny < 0 || nx < 0) continue;
			int nh = arr[ny][nx];
			//if (vt[ny][nx] == true) continue;
			if (nh >= curh) continue;
			dp[ny][nx] += dp[cury][curx];
			//cout << "  dp(" << ny << "," << nx << "):" << dp[ny][nx] << endl;
			if (isq[ny][nx] == true) continue;
			q.push({ ny, nx, nh });
			isq[ny][nx] = true;
		}
	}
	cout << dp[M - 1][N - 1];
}