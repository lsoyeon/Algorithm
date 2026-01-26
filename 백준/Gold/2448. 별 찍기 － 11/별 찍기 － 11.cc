#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
/*
n=3
2/1/2
1/1/1/1/1
5

n=6
2/1/2
1/1/1/1/1
5
2/1/5/1/2
1/1/1/1/3/1/1/1/1
5/1/5
n=12


*/
char arr[3072][6144];
void draw(int n, int y, int x) {
	if (n == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		for (int i = 0; i < 5; ++i) {
			arr[y + 2][x - 2 + i] = '*';
		}
		return;
	}
	int nn = n / 2;
	draw(nn, y, x);
	draw(nn, y + nn, x - nn);
	draw(nn, y + nn, x + nn);
}
int main(void) {
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2 * N - 1; ++j) {
			arr[i][j] = ' ';
		}
	}
	draw(N, 0, N - 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 2 * N - 1; ++j) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
	return 0;
}