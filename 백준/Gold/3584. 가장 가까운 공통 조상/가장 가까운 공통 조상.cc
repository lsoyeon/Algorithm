//parent[x][k]:x의 2^k번째 조상
//1. depth, parent[x][0] 채우기(dfs)
//2. parent[x][k] 채우기
//3. 높이가 다르면 같게 만들기
//4. 조상이 같지 않으면 건너뛰고 같지 않을때마다 이동하기
#include <iostream>
#include <vector>
#include <algorithm>
#define Nmax 10001
#define Lmax 16
using namespace std;
int dep[Nmax];
bool vt[Nmax];
vector<int> adj[Nmax];
int par[Nmax][Lmax+1];
int N, M, root;
bool isroot[Nmax];
void dfs(int x, int cnt) {
	vt[x] = true;
	dep[x] = cnt;
	for (int v : adj[x]) {
		if (vt[v] == true) continue;
		par[v][0] = x;
		dfs(v, cnt + 1);
	}
}
void preprocess() {
	for (int i = 1; i <= Lmax; i++) {
		for (int j = 1; j <= N; j++) {
			par[j][i] = par[par[j][i - 1]][i - 1];
		}
	}
}
int lca(int a, int b) {
	if (a == root || b == root) return root;
	if (dep[a] < dep[b]) {
		swap(a, b);
	}
	if (dep[a] != dep[b]) {
		for (int i = Lmax; i >= 0; i--) {
			if (dep[par[a][i]] >= dep[b]) {
				a = par[a][i];
			}
		}
	}
	if (a == b) return a;

	for (int i = Lmax; i >= 0; i--) {
		if (par[a][i] != par[b][i]) {
			a = par[a][i];
			b = par[b][i];
		}
	}
	return par[a][0];
}
void solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		adj[i].clear();
		vt[i] = false;
		for (int k = 0; k <= Lmax; k++) {
			par[i][k] = 0;
		}
		dep[i] = 0;
		isroot[i] = true;
	}
	for (int i = 0; i < N - 1; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		adj[a].push_back(b);
		isroot[b] = false;
	}
	for (int i = 1; i <= N; i++) {
		if (isroot[i]==true) {
			root = i;
		}
	}
	dfs(root, 1);
	preprocess();
	int a = 0, b = 0;
	cin >> a >> b;
	cout << lca(a, b) << "\n";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int testcase = 0; testcase < T; testcase++) {
		solve();
	}
	return 0;
}