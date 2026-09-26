#include <string.h>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
/*
n개 송전탑 - 전선 통해서 하나의 트리
전선들 중 하나 끊어서 전력망 네트워크 2개로 분할
두 전력망 갖게 되는 송전탑의 개수 최대한 비슷하게

송전탑 개수 n(100이하), 전선 정보 wires 99개 이하
두 전력망 송전탑 개수 차이 return

*/
typedef pair<int, int> pii;
vector<int> adj[101];
int vt[101];
int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    for(int i = 0 ; i<=n ; ++i) adj[i].clear();
    int len = wires.size();
    for(auto w : wires){
        int u = w[0]; int v = w[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // x, n-x -> n-2x or 2x-n
    for(auto w: wires){
        int u = w[0]; int v = w[1];
        memset(vt, 0, sizeof(vt));
        //개수 세기
        //vt[u] = 1;
        queue<int> q;
        q.push(u);
        while(!q.empty()){
            int cur = q.front(); q.pop();
            if(vt[cur]) continue;
            vt[cur] =1 ;
            for(int i = 0; i < adj[cur].size(); ++i){
                int nxt = adj[cur][i];
                if(cur == u && nxt == v) continue;
                if(cur == v && nxt == u) continue;
                if(vt[nxt]) continue;
                q.push(nxt);
            }
        }
        int cnt = 0;
        for(int k = 1; k <= n; ++k){
            if(vt[k]) cnt++;
        }
        answer = min(answer, abs(2*cnt - n));
    }
    return answer;
}