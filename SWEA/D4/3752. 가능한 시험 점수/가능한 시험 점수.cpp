#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
/*
학생들이 받을 수 있는 점수 가능한 경우의 수
조합? -- 부분합 구하기 = 총 부분집합 2^N개 -> 시간초과
dp 로 누적합
*/
int N;
vector<int> v;
int temp[101]; //현재 선택 보관
set<int> res;
int dp[10001]; //최대 합 100*100
//nCr
void comb(int n, int r, int t) {
	if (r == 0) {
		//cout << "[";
		int sum = 0;
		for (int i = 1; i <= t; ++i) {
			//cout << temp[i] <<" ";
			sum += temp[i];
		} //cout << "]\n";
		res.insert(sum);
		return;
	}
	if (n < r) return ;
	temp[r] = v[n-1];
	comb(n - 1, r - 1,t);  //포함되는 경우
	comb(n - 1, r, t); //포함되지 않는 경우
}

void solve_OD(){
	res.clear();
	res.insert(0);
	for (int i = 1; i <= N; ++i) {
		//printf("%d C %d\n", N, i);
		comb(N, i, i);
	}
	cout << res.size() << "\n";
}
void solve() {
	int cnt = 1;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (auto score : v) {
		for (int i = 10000; i >= 0; --i) {
			if (dp[i]) {
				if (!dp[i + score]) {
					dp[i + score] = 1;
					cnt++;
				} 
			}
		}
	}
	cout << cnt << "\n";
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		v.clear(); 
		for (int i = 0; i < N; ++i) {
			int tmp; cin >> tmp;
			v.emplace_back(tmp);
		}
		sort(v.begin(), v.end());
		cout << "#" << test_case << " ";
		solve();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}