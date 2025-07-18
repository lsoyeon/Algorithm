#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX
#define Nmax 501

using namespace std;

int N, r, c;
vector<pair<int,int>> v;
int dp[Nmax][Nmax];
int res;
int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> r >> c;
		v.push_back({ r,c });
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (j == i + 1) {
				dp[i][j] = v[i].first * v[i].second * v[j].second;
				//cout << i << "," << j << " :" << dp[i][j] << endl;
			}
			else dp[i][j] = INF;
		}
	}
	//사선 dp: 차이가 2부터 ~
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			for (int k = j; k < j + i; k++) {
				dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k+1][j + i] + v[j].first * v[k].second * v[j + i].second);
				//cout << j << "," << j + i << " :" << dp[j][j + i] << endl;
			}
		}
	}
	cout << dp[0][N - 1];
	return 0;
}