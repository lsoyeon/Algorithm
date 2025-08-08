#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <stack>
#include <deque>
#define MAX 100001
#define INF INT_MAX
#define SZ (1<<10)
using namespace std;
int n;
int fi[1001];
int arr[1001];
int tr[SZ * 2];
int tr2[SZ * 2];
int ans;
void update(int pos, int x, int tr[]) {
	int idx = pos + SZ;
 	tr[idx] = x;
	int tmp = idx/2;
	while (tmp >= 1) {
		tr[tmp] = max(tr[tmp * 2], tr[tmp * 2 + 1]);
		tmp /= 2;
	}
}
int query(int a, int b, int tr[]) {
	int aa = SZ + a;
	int bb = SZ + b;
	int res = 0;
	while (aa <= bb) {
		if (aa % 2 == 1) {
			res = max(res, tr[aa]);
		}
		if (bb % 2 == 0) {
			res = max(res, tr[bb]);
		}
		aa = (aa + 1) / 2;
		bb = (bb - 1) / 2;
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> arr[i];
		int max_Di = query(0, arr[i] - 1, tr);

		update(arr[i], max_Di + 1, tr);
		fi[i] = max_Di + 1;
	}

	for (int i = n-1; i >= 0; i--) {
		int max_Dj = query(0, arr[i] - 1, tr2);
		update(arr[i], max_Dj + 1, tr2);
		//ans = max(tr[arr[i]]+ max_Dj, ans);
		ans = max(fi[i] + max_Dj, ans);
	}


	cout << ans;
	return 0;
}
