#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string.h>
#include <bitset>
using namespace std;
/*
학생들이 받을 수 있는 점수 가능한 경우의 수
- 조합? -- 부분합 구하기 = 총 부분집합 2^N개 -> 시간초과
- dp 로 누적합
- bitset으로 dp 만들면 실행시간 줄일 수 있음
- dfs 방식 + 방문기록하기
*/
int N;
vector<int> v;
int temp[101]; //현재 선택 보관
set<int> res;
int dp[10001]; //최대 합 100*100
bitset<10001> dp2;
bool visited[101][10001];
bool dp3[10001];
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
void solve2() {
	dp2.reset(); dp2[0] = 1;
	//bitset의 각 bit의 자리가 가능한 점수  3번째bit = 1 --> 3점 가능
	for (auto score : v) {
		dp2 |= (dp2 << score); // dp2<<score 하면 score + 기존 점수 꼴
	}
	cout << dp2.count() << "\n";
}
void solve3() {
	int cnt = 1;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	int max_sum = 0;
	for (auto score : v) {
		for (int i = max_sum; i >= 0; --i) {
			if (dp[i]) {
				if (!dp[i + score]) {
					dp[i + score] = 1;
					cnt++;
				}
			}
		}
		max_sum += score;
	}
	cout << cnt << "\n";
}
bitset<10001> dp4;
void dfs(int idx, int sum) { //상태: 현재 idx,sum
	if (idx == N) {
		dp3[sum] = 1;
		// dp4 |= (1 << sum); 이건 bitset이 아닌 UINT64나 UINT32 비트마스킹할 때 쓰는 방법, 우항이 int형 이므로!
		dp4[sum] = 1; // or dp4.set(sum);
		return;
	}
	if (visited[idx][sum]) return;
	visited[idx][sum] = 1;
	dfs(idx + 1, sum);
	dfs(idx + 1, sum + v[idx]);
}

void solve4() {
	memset(visited, 0, sizeof(visited));
	memset(dp3, 0, sizeof(dp3));
	dp4.reset();
	dfs(0, 0);
	cout << dp4.count() << "\n";
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
		solve4();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}