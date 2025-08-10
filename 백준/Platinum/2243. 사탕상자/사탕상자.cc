#define _CRT_SECURE_NO_WARNINGS
// 사탕 상자
#include <cstdio>

#define SZ (1<<20)  // 원소의 개수 100000 은 대략 2^17

int n;
int tr[SZ * 2];     // index tree

// pos에 val 만큼 더한다. (교체가 아님)
void update(int pos, int val) {
	pos += SZ;
	tr[pos] += val;
	pos /= 2;
	while (pos >= 1) {
		tr[pos] = tr[pos * 2] + tr[pos * 2 + 1];
		pos /= 2;
	}
}

// k 번째에 해당하는 위치를 구한다.
int findk(int k) {
	int pos = 1;
	int tmp = 1;
	while (tmp < SZ) {
		if (k <= tr[tmp * 2]) {
			tmp = tmp * 2;
		}
		else {
			k -= tr[tmp * 2];
			tmp = tmp * 2 + 1;

		}  
	}

	return tmp - SZ;
}

int main() {
	scanf("%d", &n);
	while (n-- > 0) {
		int a, b, c;
		scanf("%d%d", &a, &b);
		//a가 2 : 사탕을 넣는 경우 ->B: 넣을 사탕의 맛 c: 개수
		if (a == 2) {
			scanf("%d", &c);
			// b 만큼 매운 사탕을 c만큼 추가한다.
			update(b, c);
		}
		// a가 1 : 사탕을 꺼내는 경우 -> b: 꺼낼 사탕 순위
		else {
			int x = findk(b);
			// b 번째 매운 사탕을 찾아서 출력하고
			printf("%d\n", x);
			// 그 사탕을 하나 먹는다.
			update(x, -1);
		}
	}
}