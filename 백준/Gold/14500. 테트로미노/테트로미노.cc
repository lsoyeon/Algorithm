#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
vector<int> v;
int N, M;
int arr[501][501];
/*
최댓값 찾기
거리가 4인 경로 중 최대 값


dp[거리][현재위치 y][x]? -> X
플로이드 워셜? 
*/
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0,0,1, -1 };
int vt[501][501];
int isNotRange(int y, int x) {
	return (y < 0) || (y > N - 1) || (x < 0) || (x > M - 1);
}
int res=0;

void dfs(int y, int x, int acc, int dis){
	//printf("(%d, %d) acc: %d, dis: %d\n", y, x, acc, dis);
	if (dis == 4) {
		if (res < acc) {
			res = acc;
		}
		return;
	}
	
	for (int i = 0; i < 4; ++i) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (isNotRange(ny, nx)) continue;
		if (vt[ny][nx]) continue;
		vt[ny][nx] = 1;
		dfs(ny, nx, acc + arr[ny][nx], dis + 1);
		vt[ny][nx] = 0;
	}
}



int main(int argc, char** argv)
{
	//freopen("input.txt", "r", stdin);
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int tmp; cin >> tmp; arr[i][j]=tmp;
		}
	}
	//vt[0][4] = 1;
	//dfs(0, 4, arr[0][4], 1);
#ifndef DEBUG
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			vt[i][j] = 1;
			dfs(i, j, arr[i][j], 1);
			vt[i][j] = 0;
		}
	}
	//0번째 줄 ㅜ, 마지막 줄 ㅗ
	for (int j = 1; j < M-1; ++j) {
		int tmp = arr[0][j] + arr[0][j - 1] + arr[0][j + 1] + arr[1][j];
		int tmp2 = arr[N - 1][j] + arr[N - 1][j - 1] + arr[N - 1][j + 1] + arr[N - 1][j];
		if (res < tmp) res = tmp;
		if (res < tmp2) res = tmp2;
	}
	//0번째 열 ㅏ, M-1번째 열 ㅓ
	for (int i = 1; i < N-1; ++i) {
		int tmp = arr[i][0] + arr[i - 1][0] + arr[i + 1][0] + arr[1][i];
		int tmp2 = arr[i][N - 1] + arr[i - 1][N - 1] + arr[i + 1][N - 1] + arr[N - 2][i];
		if (res < tmp) res = tmp;
		if (res < tmp2) res = tmp2;
	}
	
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j < M; ++j) {
			int tmp = arr[i][j] + arr[i - 1][j] + arr[i][j - 1] + arr[i][j + 1] + arr[i + 1][j];
			//최솟값을 찾아야해
			int candi = min(min(arr[i][j - 1], arr[i - 1][j]), min(arr[i][j + 1], arr[i + 1][j]));
			tmp -= candi;
			if (res < tmp) {
				res = tmp;
			}
		}
	}
#endif
	cout << res;
	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}
