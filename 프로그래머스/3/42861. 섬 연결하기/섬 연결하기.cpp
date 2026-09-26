#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
n개 섬 다리 건설 비용 주어짐
최소 비용으로 모든 섬 서로 통행 가능하게 만들 때 최소 비용 return
크루스칼 - 
*/
int par[101];
int find(int a ){
    if(par[a]==a) return a;
    return par[a] = find(par[a]); //find
}
void union_set(int a, int b){
    int pa = find(a); 
    int pb = find(b);
    //cout <<"a: " << a <<" b: "<<b<<endl;
    //cout <<"pa: " << pa << " pb: "<<pb <<endl;
    par[pa] = pb;
}
typedef struct EDGE{ int u; int v; int c;} Edge;
typedef pair <int, int> pii;
bool compare(const Edge& e1, const Edge&e2){
    return e1.c < e2.c;
}
vector<pii> adj[101];
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;  
    for(int i = 0;i < n; ++i) par[i]=i;
    int len = costs.size();
    vector<Edge> edges;
    for(int i = 0;i < len ; ++i){
        int u = costs[i][0]; int v = costs[i][1]; int c = costs[i][2];
        edges.push_back({u,v,c});
    }
    
    sort(edges.begin(), edges.end(), compare);

    for(auto e : edges){
        int u = e.u; int v = e.v; int c = e.c;
        if(find(u) == find(v)) continue;
            #if 1
        union_set(u,v);
            #endif
        answer += c;
    }

    return answer;
}