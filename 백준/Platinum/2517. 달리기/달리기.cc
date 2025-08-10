#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define NMAX 500001
using namespace std;
int N, M, L;
vector<pair<int, int>> org;
vector<int>after(NMAX);

int tree[NMAX * 4];
void update(int pos , int val) {
	pos += L;
	tree[pos] += val;
	while (pos > 1) {
		pos /= 2;
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
	}
}
int query(int l, int r) {
	l += L; r += L;
	int res = 0;
	for (; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res += tree[l++];
		if (~r & 1) res += tree[r--];
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int ab; cin >> ab;
		org.push_back({ ab, i });
	}
	sort(org.begin(), org.end());
	for (int i =0 ; i < N; ++i) {
		after[org[i].second] = i;//현재 i번째 사람의 실력!(실력 범위가 줄었으므로 segtree 크기 줄일 수 있음)
	}
	int h = ceil(log2(N));
	L = 1 << h;
	//(0~자기 위치 에서 자기보다 큰 숫자의 개수 +1)
	for (int i = 0; i < N; ++i) {
		update(after[i], 1);
		cout << query(after[i], N - 1) <<"\n";
	}
}