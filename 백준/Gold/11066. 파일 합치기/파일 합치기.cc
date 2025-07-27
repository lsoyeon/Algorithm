#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#define INF INT_MAX
#define Kmax 501
using namespace std;
typedef long long ll;;
int K, T;
vector<int> input;
int dp[Kmax][Kmax];//해당 파일 크기일때 최소 비용
int res;
void solve() {
	cin >> K;
	input.clear();
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		input.push_back(tmp);
		for (int j = 0; j < K; j++) {
			dp[i][j] = 0;
		}
	}
	//누적합 구하기
	for (int i = 0; i < K - 1; i++) {
		dp[i][i + 1] = input[i] + input[i + 1];
	}
	for (int i = 2; i < K; i++) {
		for (int j = 0; j < K-i ; j++) {
			dp[j][j + i] = dp[j][j + i - 1] + input[j + i];
		}
	}
    //최솟값 구하기
	for (int i = 2; i < K; i++) {
		for (int j = 0; j < K - i; j++) {
			int tmp = INF;
			for (int k = j; k < j + i; k++) {
				tmp = min(tmp, dp[j][k] + dp[k + 1][j + i]);
			}
			dp[j][j + i] += tmp;
		}
	}
	cout << dp[0][K - 1]<<"\n";
}
int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
	return 0;
}