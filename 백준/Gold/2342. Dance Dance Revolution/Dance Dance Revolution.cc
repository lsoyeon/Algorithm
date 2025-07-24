#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#define INF INT_MAX
#define Nmax 100001
using namespace std;
typedef long long ll;;
int N;
vector<int> v;
int cost[5][5];
int dp[Nmax][5][5];
int main() {
	//freopen("input.txt", "r", stdin);
	cin.tie(0); ios::sync_with_stdio(0);
	int tmp;
	while (true) {
		cin >> tmp;
		if (tmp == 0) break;
		v.push_back(tmp);
	}
	for (int i = 0; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (i == j) {
				cost[i][j] = 1;
			}
			else if (i == 0) {
				cost[i][j] = 2;
			}
			else if(((i-j) == -2 || (i-j) == 2)){
				cost[i][j] = 4;
			}
			else {
				cost[i][j] = 3;
			}
		}
	}



	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	int r = 0, l = 0;
	dp[0][v[0]][0] = cost[0][v[0]];
	dp[0][0][v[0]] = cost[0][v[0]];
	for (int j = 1; j < v.size(); j++) {
		int des = v[j];
		//cout << "des:"<< des << "\n";
		for (int i = 0; i < 5; i++) {
			for (int k = 0; k < 5; k++) {
				int tmp = dp[j - 1][i][k];
				if (tmp !=INF) {
					dp[j][i][des] = min(dp[j][i][des], tmp + cost[k][des]);
					dp[j][des][k] = min(dp[j][des][k], tmp + cost[i][des]);
					//cout << dp[j][des][k] << endl;
					//cout << dp[j][i][des] << endl;
				}
			}
		}
		//cout << "--------------------" << endl;
	}
	int last_idx = v.size() - 1;
	int last_des = v[last_idx];
	int res = INF;
	for (int i = 0; i < 5;i++) {
		res = min(res, min (dp[last_idx][i][last_des], dp[last_idx][last_des][i]));
	}
	cout << res;
	return 0;
}