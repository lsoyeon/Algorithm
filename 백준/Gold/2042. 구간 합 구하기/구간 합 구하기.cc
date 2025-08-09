#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
typedef long long LL;
typedef long long ll;
int n, m, k;
LL tr[1 << 21];
void update(int pos, ll val) {
	// 말단 노드로 인덱스 조정 (+ 배열 사이즈)
	pos = pos + (1 << 20);
	// 자기자신 update
	tr[pos] = val;
	// 부모 update
	pos /= 2;
	while (pos >= 1) {
		tr[pos] = tr[pos * 2] + tr[pos * 2 + 1];
		pos /= 2;
	}
}

ll sum(int from, int to) {
	ll res = 0;
	from += 1 << 20;
	to += 1 << 20;
	while (from <= to) {
		// from 입장
		// from 홀수면 직접 노드 sum 사용 + 다음 부모 노드로 올라가기
		// from 짝수면 바로 부모 노드로 올라가기
		if (from % 2 == 1) {
			res += tr[from];
		}
		from = (from + 1) / 2;

		// to 입장
		// to  홀수면 직접 노드 sum 사용 + 다음 부모 노드로 올라가기
		// to 짝수면 바로 부모 노드로 올라가기
		if (to % 2 == 0) {
			res += tr[to];
		}
		to = (to - 1) / 2;
	}
	return res;
}

int main(void) {
	scanf("%d%d%d", &n, &m, &k);
	//printf("%d %d %d", n, m, k);
	// index가 0으로 시작하는지 , 1로 시작하는지 문제 잘 보기
	for (int i = 1; i <= n; i++) {
		ll a;
		scanf("%lld", &a);
		update(i, a);
	}
	for (int i = 0; i < (m + k); i++) {
		ll a, b, c;
		scanf("%lld%lld%lld", &a, &b, &c);
		if (a == 1) {
			update(b, c);
		}
		else {
			printf("%lld\n", sum(b, c));
		}
	}
	return 0;
}