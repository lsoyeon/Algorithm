#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>
#include <math.h>
using namespace std;

/*
탑 N개
-  탑 X-Y 평면
- 맨 처음 D 에너지
- 탑 사정거리 R

[탑이 적을 공격]
- 자신의 에너지 재분배
(서로 다른 두 탑 거리 <= R : 둘 중 한 탑, 절반 전송 가능 -10 +5)
- 적과 탑의 거리 <= R 
- 자신의 모든 에너지를 적을 공격 = 적이 받는 데미지

적이 받을 수 있는 에너지의 최댓값 구하기
1) 적과 거리가 R 이하인 top들 구하기
2) 해당 top들 로부터 다른 점들 최단 거리 구하기
*/
int N, D, demonx, demony; //초기에너지 D
double R;
typedef pair<int, int> pii;
inline double demon_dis (int x, int y) {
	return sqrt((x - demonx) * (x - demonx) + (y - demony) * (y - demony));
}
inline double dis(pii p1, pii p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}
vector <int> near;
vector<int> tops; //near이 아닌 top들
int energy[51];
pii pos[51]; // 모든 top들의 좌표 저장
vector <int> graph[51]; //graph로 연결
int d[51];
int vt[51] = { 0, };
int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);

	cin >> N >> R >> D >> demonx >> demony;
	for (int i = 1; i <= N; ++i) {
		// 탑 x, y 좌표
		int x, y;
		cin >> x >> y;
		energy[i] = 10; pos[i] = make_pair(x, y);
		if (demon_dis(x, y) <= R) {
			near.push_back(i);
			graph[0].emplace_back(i);
			graph[i].emplace_back(0);
		}
		else {
			tops.push_back(i);
		}
		d[i] = 987654321;
	}
	//그래프 만들기 
	for (int i = 1; i <= N; ++i) {
		for (int j = i+1; j <= N; ++j) {
			if (i == j) continue;
			if (dis(pos[i], pos[j]) <= R) {
				graph[i].emplace_back(j);
				graph[j].emplace_back(i);
			}
		}
	}

	//0번 점에서 각 점까지의 최단 거리 
	queue<pii> q; //id, 거리
	q.push({ 0, 0 });
	vt[0] = 1;
	while (!q.empty()) {
		int cur = q.front().first;
		int cur_dis = q.front().second;
		q.pop();
		int sz = graph[cur].size();
		for (int k = 0;k < sz; ++k){
			int i = graph[cur][k];
			if (vt[i]) continue;
			
			if(cur_dis + 1 < d[i]){
				d[i] = cur_dis + 1;
				q.push({ i, d[i] });
				vt[i] = 1;
			}
		}
	}
	double res = 0;
	for (int i = 1; i <= N; ++i) {
		//cout << i << "와 적과의 최단 거리 : " << d[i] << endl;
		res += D * pow(0.5, d[i] - 1);
	}
	printf("%.2f", res);
}