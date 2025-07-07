#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
#include <tuple>
#include <unordered_set>
using namespace std;
typedef long long ll;
unordered_map<ll, int> mmap;

/*
팔려는 나무 길이(자연수) 전부 같게 

나무를 한번 자를 때 C원
나무 팔 때 : 한 단위에 W

현재 가지고 있는 나무 길이 주어졌을 때 가장 벌 수 있는 큰돈

*/
int N, C, W;
vector<int> v;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> N >> C >> W;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int max_len = v[N-1];
	ll max_ret = 0; 
	for (int len = max_len; len >= 1; --len) {
		ll sum = 0; ll cut = 0;
		for (auto& t : v) {
			ll cost = 0;
			int num = (t / len);
			if (num == 0) continue;
			if (t % len == 0) {
				cut += num - 1;
				cost = num * W * len - (num - 1) * C;
			}
			else {
				cost = num * W * len - (num) * C;
			}
			if (cost > 0) sum += cost;
		}
		//int cmp = NC + sum*( len * W - C);
		if (sum > max_ret) {
			//cout << len<<"\n";
			max_ret = sum;
		}
	}
	cout << max_ret;
	return 0;
}