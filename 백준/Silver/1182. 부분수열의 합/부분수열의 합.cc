#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define SMAX 1000006
#define NMAX 20
#define MAX 100005
/*
N개의 정수로 이루어진 수열, 크기 양수인 부분수열 중 더한값이 S가 되는
- 조합?
- dp
- dfs
*/
int N, S;
vector<int> v;
bitset<SMAX + 1> sum;
unordered_map<int, int> dp;

void solve() {
	dp[0] = 1;
	int num_max = 0; int num_min = 0;
	for (auto num : v) {
		//cout << "num: " << num << endl;
		if (num > 0) {
			for (int i = num_max; i >= num_min; --i) {
				if (i == 0) {
					dp[num + i] += dp[0];
					//printf("dp[%d] += dp[0] : %d\n", num + i, dp[num + i]);
				}
				else if (dp[i] > 0) {
					dp[num + i]+=dp[i];
				}
			}
			num_max += num;
		} 
		else {
			for (int i = num_min; i <= num_max; ++i) {
				if (i == 0) {
					dp[num + i] += dp[0]; 
					/*
					1
					2
					4

					*/
					//cout << dp[0] << "\n";
				}
				else if (dp[i] > 0) {
					dp[num + i] += dp[i];
				}
			}
			num_min += num;
		}
	}
	--dp[0];
	cout << dp[S];
}
bool comp(int a, int b) {
	return a > b; // 내림차순
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		int tmp; cin >> tmp;
		v.emplace_back(tmp);
	}
	sort(v.begin(), v.end()); //오름차순
	solve();
}