#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define Nmax 16
#define INF 987654321
using namespace std;
typedef pair <int, int> pii;
int N;
int w[Nmax][Nmax];
int dp[Nmax][1 << Nmax]; // [정점] [현상태]
int final;
int solve(int cur, int state) {
	if (state == final) {
		if (w[cur][0] == 0) return INF;
		else return w[cur][0];
	}
	if (dp[cur][state] != -1) return dp[cur][state];
	dp[cur][state] = INF;
	//최소비용을 구해보자
	for (int i = 0; i < N; i++) {
		if (w[cur][i] == 0) continue;
		//이미 다녀온 곳이면 패스
		if ((state & (1 << i)) == (1 << i)) continue;
		dp[cur][state] = min(dp[cur][state], w[cur][i]+solve(i, (state | (1 << i))));
	}
	return dp[cur][state];
}
int main() {
	cin >> N;
	// 순환여행 경로
	// 한번 갔던 도시는 다시 갈 수 없다.
	// 가장 적은 비용
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> w[i][j];
		}
	}
	if (N == 2) {
		cout << w[0][1] + w[1][0];
		return 0;
	}
	final = (1 << N)-1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < final; j++) {
			dp[i][j] = -1;
		}
	}
	cout << solve(0, 1);
	return 0;
}