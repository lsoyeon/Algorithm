#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define NMAX 500005
#define IDMAX 1000006
using namespace std;
int N, M, L;

vector<int>a(NMAX);
vector<int>b(NMAX);
long long tree[NMAX * 4];
int ids[IDMAX];
void update(int pos , int val) {
	pos += L;
	tree[pos] += val;
	while (pos > 1) {
		pos /= 2;
		tree[pos] = tree[pos * 2] + tree[pos * 2 + 1];
	}
}
int query(int l, int r) {
	if (l > r) return 0;
	l += L; r += L;
	long long res = 0;
	for (; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) res += tree[l++];
		if (~r & 1) res += tree[r--];
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	int h = ceil(log2(N));
	L = 1 << h;
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
		ids[b[i]] = i; //끝 인덱스
	}
	long long res = 0;
	for (int i = 0; i < N; ++i) {
		
		res += query(ids[a[i]] + 1, N - 1);
		update(ids[a[i]], 1);
		//printf("query[%d, %d] : %d\n", ids[a[i]] + 1, N - 1, query(ids[a[i]] + 1, N - 1));
	}
	cout << res;
	return 0;
}