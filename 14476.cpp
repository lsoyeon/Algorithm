#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
// 계산하는 과정, 자료형, 범위 터지지 않는지
// 엣지 케이스 경우 고려하기
int n, k, max = -1;
int left[1000050];//0~i번째까지의 gcd
int arr[1000000];
int gcd(int a, int b) {
	int r;
	while (b != 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	left[0] = arr[0];
	for (int i = 1; i < n; i++) {
		// 0 ~ i번째까지의 gcd
		left[i] = gcd(left[i - 1], arr[i]);
	}
	//초기  right
	int right = arr[n - 1];
	// n-1번째를 빼는 경우
	if (left[n-2] > max && (arr[n-2] % left[n-2] != 0)) {
		k = arr[n-1];
		max = left[n-2];
	}
	// i번째를 뺀다
	for (int i = n-2 ; i > 0; i--) {
		// n-1 ~ i+1번째까지의 gcd
		right = gcd(right, arr[i+1]);
		int g = gcd(left[i - 1], right);
		if ( g > max && (arr[i]%g != 0)) {
			k = arr[i];
			max = g;
		}
	}
	//0번째를 빼는경우
	right = gcd(right, arr[1]);
	if (right > max && (arr[0] % right != 0)) {
		k = arr[0];
		max = right;
	}
	if (max == -1) {
		printf("-1");
		return 0;
	}
	printf("%d %d", max, k);
	return 0;
}