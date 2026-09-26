#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;
/*
n개의 나라, 양방향 토로, 걸리는 시간 다 다름.
1번 마을에서 각 마을로 음식 배달, 음식 주문 받을 때
N개 마을 중에서 K 시간 이하로 배달 가능한 마을만!!!
벨만포드로 1 : N 최단 거리 다 구하기 
Edge 2000이하
N 1~50 
*/
typedef pair<int, int> pii;
vector<pii> adj[51];
int dp[51];
int vt[51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int E = road.size();
    for(int i =0 ;i < E ; ++i){
        adj[road[i][0]].push_back({road[i][1], road[i][2]});
        adj[road[i][1]].push_back({road[i][0], road[i][2]});
    }
    priority_queue<pii, vector<pii>> pq;
    fill(&dp[0], &dp[51], 987654321);
    memset(vt, 0, sizeof(vt));
    pq.push({0, 1}); dp[1]= 0;
    while(!pq.empty()){
        int cur = pq.top().second;
        int dis = pq.top().first; pq.pop();
        if(dp[cur] < dis) continue;
        vt[cur] =1;
        int sz = adj[cur].size();
        for(int i =0 ; i < sz ; ++i){
            int nxt = adj[cur][i].first;
            int nxt_dis = adj[cur][i].second;
            int tmp = dis + nxt_dis;
            //if(vt[nxt]) continue;
            if(dp[nxt] > tmp){
                dp[nxt] = tmp;
                pq.push({tmp, nxt});
            }
        }
    }
    for(int i = 1; i<= N ; ++i){
        if(dp[i] <= K ){
            cout << i << " ";
            answer++;
        }
    }
    return answer;
}