#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
/*
지점 번호 : 1~n
edge : n*(n-1)/2 이하 -> 두 지점 당 길 한개
요금 : 100,000 이하

a,b 출발해서 각각 도착 지점까지 이동, 최저 예상 택시 요금
합승 하지 않고 각자 이동하는게 더 낮다면 합승 안하기.

출발지점(s) ~ 모든 지점 : 최단 거리 구하기
a 도착지점 ~ 모든 지점
b 도착 지점 ~ 모든 지점
*/

typedef long long ll;
typedef pair<long long, int> pli;
ll s_dis[201];
ll a_dis[201];
ll b_dis[201];
vector<pair<int, int>> adj[201];
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    int sz = fares.size();
    for(int i = 0; i <=n ; ++i) adj[i].clear();
    for(int i = 0;i < sz ; ++i){
        adj[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        adj[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    fill(&s_dis[0], s_dis+201, 987654321); s_dis[s] = 0;
    fill(&a_dis[0], a_dis + 201, 987654321); a_dis[a] = 0;
    fill(&b_dis[0], b_dis + 201, 987654321); b_dis[b] = 0;
    #if 1
    priority_queue<pli, vector<pli>, greater<pli>> pq; //현재 거리, 현재 위치
    pq.push({0, s});
    while(!pq.empty()){
        ll cur_dis = pq.top().first;
        ll cur_pos = pq.top().second;
        pq.pop();
        if(s_dis[cur_pos] < cur_dis) continue;
        int len = adj[cur_pos].size();
        for(int i = 0;i < len ; ++i){
            int next_pos = adj[cur_pos][i].first;
            ll next_dis = cur_dis + adj[cur_pos][i].second;
            if(next_dis < s_dis[next_pos]){
                s_dis[next_pos] = next_dis;
                pq.push({next_dis, next_pos});
            }
        }
    }
    pq.push({0, a});
    while(!pq.empty()){
        ll cur_dis = pq.top().first;
        ll cur_pos = pq.top().second;
        pq.pop();
        if(a_dis[cur_pos] < cur_dis) continue;
        int len = adj[cur_pos].size();
        for(int i = 0;i < len ; ++i){
            int next_pos = adj[cur_pos][i].first;
            ll next_dis = cur_dis + adj[cur_pos][i].second;
            if(next_dis < a_dis[next_pos]){
                a_dis[next_pos] = next_dis;
                pq.push({next_dis, next_pos});
            }
        }
    }
    pq.push({0, b});
    while(!pq.empty()){
        ll cur_dis = pq.top().first;
        ll cur_pos = pq.top().second;
        pq.pop();
        if(b_dis[cur_pos] < cur_dis) continue;
        int len = adj[cur_pos].size();
        for(int i = 0;i < len ; ++i){
            int next_pos = adj[cur_pos][i].first;
            ll next_dis = cur_dis + adj[cur_pos][i].second;
            if(next_dis < b_dis[next_pos]){
                b_dis[next_pos] = next_dis;
                pq.push({next_dis, next_pos});
            }
        }
    }

    answer = s_dis[a] + s_dis[b];
    for(int i = 1; i <= n ; ++i){
        ll tmp = s_dis[i] + a_dis[i] + b_dis[i];
        if((ll)answer > tmp) answer = tmp;
    }
    #endif
    return answer;
}