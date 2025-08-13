#include <iostream>
#define endl "\n"
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <string.h>
#include <cmath>
#define NMAX 1001
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int N;
double E;
long long L;
double dis[NMAX][NMAX];
vector<tuple<double ,int, int>> edges;
int par[NMAX];
int ranks [NMAX];
int x[NMAX]; int y[NMAX];
    /*
    모든 섬 연결 - MST 알고리즘
    환경부담세율 E, 해저터널 길이 L
    E * L^2
    */
double cal_dis (int x1,int y1, int x2,  int y2){
    ll dx = x1 - x2; ll dy = y2 - y1;
    return sqrt( dx*dx + dy*dy);
}
int find(int k){
    if(par[k] == k) return k;
    return par[k] = find(par[k]);
}
void un(int a, int b){
    int ra = find(a);
    int rb = find(b);
    if(ranks[ra] < ranks[rb]){
        par[ra] = rb;
        ranks[rb] += 1;
    } else{
        par[rb] = ra;
        if(ranks[ra] == ranks[rb]){
            ++ranks[ra];
        }
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
   // freopen("input.txt", "r", stdin);
    int T ; cin >> T; 
    //cout <<"T: " <<T<<endl;
    for(int test_case =1 ; test_case <= T ; ++test_case){
        cin >> N; 
        //cout <<"N: " << N <<endl;
        vector<tuple<double, int, int>> mst;
        edges.clear();
        fill(x, x+ N, 0); fill(y, y+ N, 0);
        for(int i = 0 ;i < N ;++i) {
            cin >> x[i];
        }
        for(int i = 0 ;i < N ;++i) {
            cin >> y[i];
        } 
        cin >> E;

        for(int i = 0 ;i < N ;++i) {
            par[i] = i; ranks[i] = 0;
            for(int j = i+1 ; j < N ; ++j){
                if(i == j){
                    dis[i][j] = 0;
                } 
                else {
                    dis[i][j] = cal_dis (x[i], y[i], x[j], y[j]);
                    dis[j][i] = dis[i][j];
                    edges.push_back({dis[i][j], i, j});
                }
            }
        }
        sort(edges.begin(), edges.end());
        double sum =0;
        int edge_cnt=0;
        for(auto&x : edges){
            if(edge_cnt == N-1) break;
            double dis; int n1, n2;
            tie(dis, n1, n2)=  x;
            if(find (n1) != find(n2)){
                un(n1, n2);
                sum += (dis * dis)* E;
                mst.push_back(x);
                edge_cnt++;
            } 
        }
        cout <<"#" <<test_case <<" " << (ll)round(sum) <<endl; 
    }
    return 0;
}