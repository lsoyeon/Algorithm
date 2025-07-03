#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
#define DIV 1000
typedef long long ll;
ll B;
int N;
vector<vector<int>> m;
/*
백준 10830 행렬제곱
구하는 것 : 행렬 A의 B제곱을 1000으로 나눈 나머지
*/
typedef vector<vector<int>> vvi;
unordered_map<ll, vvi> memo;

vector<vector<int>> multiplyMatrix(const vvi& m1, const vvi& m2) {
	vvi res(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
			res[i][j] %= DIV;
		}
	}
	return res;
}

vvi solve(const vvi& m, ll b) {
	if (b == 1) return m;
	if (memo.count(b)) return memo[b];

	//홀수이면
	if (b & 1) {
		return memo[b] = multiplyMatrix(m, solve(m, b - 1));
	}
	else {
		vvi half = solve(m, b / 2);
		return memo[b] = multiplyMatrix(half, half);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N >> B;
	vvi m(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> m[i][j];
		}
	}

	// B가 1인 경우를 별도로 처리
	if (B == 1) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << m[i][j] % DIV << " ";
			} cout << "\n";
		}
		return 0;
	}

	vvi res = solve(m, B);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << res[i][j] << " ";
		} cout << "\n";
	}
	return 0;
}