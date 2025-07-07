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
우리나라 군대 표시 x, 번호로 표시
한번호의 군대병사가 절반 초과 --> 해당 땅 그 번호 군대 지배
**: 각땅을 지배하는 군대의 번호 출력(전쟁중이면  “SYJKGW”을 쌍 따옴표 없이 출력한다.)
땅의 개수 200이하
각 땅 병사수 : 100000 이하

i번째 줄
i번째 땅의 병사수 - 병사들 군대 번호
*/
int n; //200이하
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	cin >> n;
	int num; 
	ll tmp;
	for (int i = 0; i < n; ++i) {
		cin >> num; double cmp = (num / 2.0);
		mmap.clear();
		int max_ = 0; 
		ll best = 0;
		for (int j = 0; j < num; ++j) {
			cin >> tmp;
			++mmap[tmp];
			//cout << "mmap[" << tmp << "]:" << mmap[tmp] << "\n";
			if (max_ < mmap[tmp]) {
				max_ = mmap[tmp];
				best = tmp;
			}
		}
		if (max_ > cmp) {
			cout << best << "\n";
		}
		else {
			cout << "SYJKGW" << "\n";
		}
	}
	return 0;
}