#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
#include <tuple>
using namespace std;
/*
백준 1976
중복 포함 : 경로 가능 여부
노드들끼리 모두 연결되어 있는지?
union-find 이용 : 노드들끼리 같은 집합에 속해있는지
*/
int N, M;
int par[201];
//root 찾기
int find(int x) {
	if (par[x] == x) return x;
	else return par[x] = find(par[x]);
}
void un (int a, int b) {
	int ra = find(a);
	int rb = find(b);
	if (ra < rb) par[rb] = ra;
	else par[ra] = rb;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		par[i] = i;
	}
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			int tmp; cin >> tmp;
			if (tmp) un(i, j);
		}
	}



	int st; int tmp; cin >> tmp;
	st = find(tmp);
	for (int i = 1; i < M; ++i) {
		cin >> tmp;
		if (st != find(tmp)) {
			cout << "NO"; return 0;
		}
	}
	cout << "YES";
	return 0;
}