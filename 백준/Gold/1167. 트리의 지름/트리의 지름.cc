#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define Nmax 100001
#define INF 987654321
using namespace std;
typedef pair <int, int> pii;
int N;
vector<pii> adj[Nmax];
bool vt[Nmax];
int ans = 0;
int maxnode = 0;
void dfs(int v, int dis) {
	//cout << v << endl;
	vt[v] = true;
	if (ans < dis) {
		ans = dis;
		maxnode = v;
	}
	for (int i = 0; i < adj[v].size(); i++) {
		int next = adj[v][i].first;
		int next_d = adj[v][i].second;
		if (vt[next] == true) continue;
		//cout << "next:" << next << " " << "next_d:" << next_d << endl;
		dfs(next, dis + next_d);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//트리의 지름 구하기
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int v, dis, tmp;
		cin >> tmp;
		while (true) {
			cin >> v;
			if (v == -1) break;
			cin >> dis;
			adj[tmp].push_back({ v, dis });
		}
	}
	if (N == 2) {
		cout << adj[1][0].second;
		return 0;
	}
	dfs(1, 0);
	for (int i = 1; i <= N; i++) {
		vt[i] = false;
	}
	ans = 0;
	dfs(maxnode, 0);
	
	cout << ans;
	return 0;
}