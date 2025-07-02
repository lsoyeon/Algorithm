#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
using namespace std;
#define M 1000000
#define P 1500000
typedef long long ll;
ll N;
int fibo[1500000];
/*
구하는 것 : 피보나치수를 M으로 나눈 나머지 

피사노 주기 : 피보나치수를 특정값을 나눌 때 일정 주기
주기 P = 15 * 10^(k-1) , M = 10^k (k>2)
(N 번째 피보나치 수) % M == (N % P번째 피보나치 수) % M

DIV로 나눈 나머지 --> M = DIV = 10^6 --> P = 15 * 10^5
P주기까지 반복문으로 "M으로 나눈 피보나치 수 의 나머지" 구한 뒤 저장
n%p번째 피보나치 수 나머지 출력
*/
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	fibo[0] = 0; fibo[1] = 1;
	if (N == 0) cout << 0;
	else if (N == 1) cout << 1;
	else {
		for (int i = 2; i < P; ++i) {
			fibo[i] = (fibo[i - 2] + fibo[i - 1]) % M;
		}
		cout << fibo[N % P];
	}
	cout << "\n";
	return 0;
}