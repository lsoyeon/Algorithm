#include<iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <set>
#define div (1000000007)
#define MAXN 100000
using namespace std;
bool isprime[MAXN + 1];
vector<int> primes;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	//소수 전처리
	for (int i = 0; i <= MAXN; ++i) isprime[i] = 1; //모두 true로 초기화
	isprime[1] = false; isprime[0] = false;
	for (int i = 2; i * i <= MAXN; i++) {
		if (!isprime[i]) continue; //소수가 아니면 pass
		for (int j = i * i; j <= 100000; j += i) {
			isprime[j] = false;
		}
	}
	for (int i = 2; i <= MAXN; ++i) {
		if (isprime[i]) {
			primes.push_back(i);
		}
	}
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		long long ans = 1;
		cin >> n >> k;
		//TODO: nCk 의 약수의 개수를 구하여라.
		//1. 소인수분해
		unordered_map <int, int> um; // 소수, 지수
		for (int prime : primes) {
			if (prime > n) break;
			int factor_cnt = 0;
			int temp_n = n;
			while (temp_n) {
				temp_n /= prime;
				factor_cnt += temp_n;
			}

			int temp_k = k;
			while (temp_k) {
				temp_k /= prime;
				factor_cnt -= temp_k;
			}
			int temp_nk = n - k;
			while (temp_nk) {
				temp_nk /= prime;
				factor_cnt -= temp_nk;
			}

			if (factor_cnt > 0) {
				long long tmp = (factor_cnt + 1) % div;
				ans = (ans * tmp) % div;
			}
		}

		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}