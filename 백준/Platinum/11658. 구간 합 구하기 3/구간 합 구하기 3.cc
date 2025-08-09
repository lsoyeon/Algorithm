#include <iostream>
#include <cmath>
#include <algorithm>
#define NMAX 1025
using namespace std;
int N, M, L;
int arr[NMAX][NMAX];
long long t[NMAX * 2][NMAX * 2];
void build() {
	int h = ceil(log2(N)); 
	L = 1 << h;
	//L = N;
	//말단row - 말단 col 채우기
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			t[i + L][j + L] = arr[i][j];
		}
	}
	//말단 row - 말단 아닌 col 채우기
	//cout << "0번째 row 말단- 말단 아닌 col 채우기" << endl;
	for (int r = 0; r < N; ++r) {
		for (int c = L-1; c > 0;--c) {
			t[L + r][c] = t[L + r][c<<1] + t[L + r][c<<1|1];
			//if (r == 0) {
			//	cout <<"t["<< c<<"]: " << t[L + r][c] << " ";
			//}cout << endl;
		}
	}
	//말단 아닌 row - 말단 아닌 row 채우기
	for (int r = L - 1; r > 0; --r) {
		for (int c = 1; c < 2*L; ++c) {
			t[r][c] = t[r << 1][c] + t[(r << 1) | 1][c];
		}
	}
	/*
	printf("0번째 row tree");
	for (int i = L + N-1; i > 0;  --i) {
		printf("%d ", t[L][i]);
	} printf("\n");
	printf("1번째 row tree");
	for (int i = L + N-1; i > 0; --i) {
		printf("%d ", t[L+1][i]);
	} printf("\n");
	printf("두 row tree의 부모 tree");
	for (int i = L + N-1; i > 0; --i) {
		printf("%d ", t[L>>1][i]);
	} printf("\n");

	printf("2번째 row tree");
	for (int i = L + N - 1; i > 0; --i) {
		printf("%d ", t[L+2][i]);
	} printf("\n");
	printf("3번째 row tree");
	for (int i = L + N - 1; i > 0; --i) {
		printf("%d ", t[L + 3][i]);
	} printf("\n");
	printf("두 row tree의 부모 tree");
	for (int i = L + N - 1; i > 0; --i) {
		printf("%d ", t[(L+2) >> 1][i]);
	} printf("\n");
	printf("root 노드\n");
	for (int i = L + N - 1; i > 0; --i) {
		printf("%d ", t[(L + 2) >> 2][i]);
	} printf("\n");
	*/
}
void update2(int x, int y, int c) {
	arr[x][y] = c;
	//말단 row - 모든 col update
	int posy = L + y;
	for (t[x+L][posy] = c; posy > 1; posy >>= 1) {
		t[x+L][posy >> 1] = t[x+L][posy] + t[x+L][posy ^ 1];
	}
	//말단 아닌 row update
	int posx = L + x;
	for (; posx > 1; posx >>= 1) {
		for (posy = L + y; posy > 1; posy >>= 1) {
			t[posx >> 1][posy] = t[posx][posy] + t[posx ^ 1][posy];
		}
	}
}

void update(int x, int y, int c) {
	long long diff = c - arr[x][y];
	arr[x][y] = c;
	for (int i = x + L; i > 0; i >>= 1) {
		for (int j = y + L; j > 0; j >>= 1) {
			t[i][j] += diff;
		}
	}
}
long long query1d(int x, int y1, int y2) {
	//printf("query1d(%d, %d, %d) : ", x, y1, y2 );
	long long ret = 0;
	for (y1 += L, y2 += L; y1 <= y2; y1 >>= 1, y2 >>= 1) {
		if (y1 & 1) ret += t[x][y1++];
		if ((y2 & 1)==0) ret += t[x][y2--];
	}
	//printf("ret : %d \n", ret);
	return ret;
}
long long query(int x1, int y1, int x2, int y2) {
	long long ret = 0;
	for (x1 += L, x2 += L; x1 <= x2; x1 >>= 1, x2 >>= 1) {
		if (x1 & 1) {
			ret += query1d(x1++, y1, y2);
		}
		if ((x2 & 1) == 0) {
			ret += query1d(x2--, y1, y2);
		}
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> arr[i][j];
		}
	}
	build();
	for (int i = 0; i < M; ++i) {
		int w; cin >> w;
		if (w) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query(x1-1, y1-1, x2-1, y2-1)<<"\n";
		}
		else {
			int x, y, c;
			cin >> x >> y >> c;
			update(x-1, y-1, c);
		}
	}
}