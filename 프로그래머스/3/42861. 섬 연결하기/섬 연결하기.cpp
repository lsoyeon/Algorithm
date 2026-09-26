#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
/*
n개 섬 다리 건설 비용 주어짐.
서로 통행 가능하도록 최소 비용 return
다리를 여러번 건너더라도, 도달할 수 있으면 통행 가능함
섬의 개수 n :  100 이하

최소 스패닝 트리 
1) prim 알고리즘 - 
2) kruskal 알고리즘 - disjoint set
- 간선 weight 비용순 오름차순 정렬
- 최소비용 간선 붙여나가기 
- cycle 생기면 Elog V
- 연결시킨 edge 개수 = 정점 개수가지점 개수가지 
*/

int par [101];
int find (int a){
    if (par[a] == a){
        return a;
    }
    return par[a] = find(par[a]); //경로 압축
}
void union_set (int a, int b){
    int pa = find(a);
    int pb = find(b);
    
    par[pa] = pb;
}
void init(int n){
    for(int i = 0; i < n ; ++i){
        par[i]=i;
    }
}
typedef pair<int, int> pii;
vector<pair<int, pii> > edges;
vector<pair<int, int>> adj[101]; //인접 리스트 (node, dis)
int vt[101]; //
int solution(int n, vector<vector<int>> costs) {
    int answer =0;
    int cnt = costs.size();
    for(int i = 0 ;i < cnt ; ++i){
        adj[costs[i][0]].push_back({costs[i][1], costs[i][2]});
        adj[costs[i][1]].push_back({costs[i][0], costs[i][2]});
    }
    
    priority_queue< pii , vector<pii> , greater<pii> > pq; //최소힙 < dis, node >
    //vt[0] = 1;
    pq.push({ 0, 0});
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int dis = pq.top().first;
        cout << "cur: " << cur << "dis: " << dis << endl;
        pq.pop();
        
        if(vt[cur]) continue;
        vt[cur] = 1;
        answer += dis;
        int sz = adj[cur].size();
        for(int i = 0 ; i < sz ; ++i){
            int nxt = adj[cur][i].first;
            int new_dis = adj[cur][i].second;
            
            if(vt[nxt]) continue;
            pq.push({new_dis, nxt});
            cout << "new_dis : " << new_dis << " nxt : " << nxt << endl;
        }
    }
    
    
#ifdef KRSUKAL(ELOGV)
    int answer = 0;
    int cnt = costs.size();
    for(int i = 0;i < cnt ;++i){
        edges.push_back({costs[i][2], {costs[i][0], costs[i][1]}});
    }
    sort(edges.begin(), edges.end()); //오름차순 정렬 (작은것부터)
    init(n);
    for(int i = 0 ;i < cnt ; ++i){
        int dis = edges[i].first;
        int na = edges[i].second.first;
        int nb = edges[i].second.second;
        //만약 이미 연결되어 있다면 pass하기
        if(find(na)==find(nb)) continue;
        answer += dis;
        union_set(na, nb);
    }
#endif
    
    
    return answer;
}