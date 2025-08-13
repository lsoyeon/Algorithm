#include <iostream>
#define endl "\n"
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <unordered_set>
#include <deque>
#include <unordered_map>
#include <string.h>
#include <cmath>
#define NMAX 10005
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int arr[NMAX+1];
vector<int> v;
int N, x, d; ll K;
/*
N개의 수, K
x = 0, D=1
1. x에 D 더하기
2. D에 N개의 수 중 하나 더하기
*/
unordered_map<ll, int> vt;
vector<ll> candi;
struct pair_hash {
    size_t operator()(const pair<ll, ll>& p) const {
        return hash<ll>()(p.first) ^ (hash<ll>()(p.second) << 1);
    }
};
//unordered_map<pair<ll,ll>, ll, pair_hash> map;
unordered_map<ll, ll> map;
struct State{
    ll x;
    //ll d;
    ll cnt;
    State(int _x,  int _cnt){
        x = _x;  cnt = _cnt;
    }
};
struct cmp {
    bool operator() (State& s1, State&s2){
        if( s1.cnt == s2.cnt){
            return s1.x < s2.x;
            
        }
        return s1.cnt > s2.cnt; //최소힙
    }
};
unordered_map<ll, int> distfwd ;
unordered_map<ll, int> distbwd; 
unordered_map<pair<ll,ll>, int, pair_hash> dist;
struct Node {
    ll cost; //덧셈횟수
    ll value; //현재 숫자값
    //작은 게 우선순위가 크다.
    bool operator > (const Node& other) const{
        return cost > other.cost; 
    }
};
int main(void){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // freopen("input.txt", "r", stdin);
    int T; cin >> T; 
    for(int t = 1; t <= T ; ++t){
        cin >> N;
       
        x = 0; d = 1;
        v.resize(N); map.clear(); vt.clear();candi.clear();
        for(int i= 0;i <N ;++i){
            cin >> v[i];
        }  
        cin >> K;
        unordered_map<ll, ll> mincost; //[지점] = 비용
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, K}); //비용, 시작점
        mincost[K]=0; 
        ll res = -1;
        while(!pq.empty()){
            ll cur = pq.top().value;
            ll cost = pq.top().cost;
            pq.pop();
            if(mincost.count(cur)>0 && cost > mincost[cur]  ) continue;

            if(cur == 0) {
                res = cost;
                break;
            }

            for (ll d : v){
                ll nextx = cur / d;
                ll w = cur % d;
                int newc = cost + w;

                if(mincost.find(nextx) == mincost.end() || newc < mincost[nextx]){
                    mincost[nextx] = newc;
                    pq.push({newc, nextx});
                }
            }
        }
        cout << "#" << t<< " " << res<< endl;
        /*
        0-1 bfs : deque 자료구조
        */
        #if 0
        deque<pair<ll, ll>> dq; 
        dist.clear();
        dq.push_front({0,1});
        dist[{0,1}] = 0;
        while(!dq.empty()){
            ll cx = dq.front().first;
            ll cd = dq.front().second;
            int cnt = dist[{cx, cd}];
            dq.pop_front();
            if(cx > K || (cx < K && cd > K - cx)){
                continue;
            }
            if(cx == K) {
                cout << "#" << t <<" " << dist[{cx, cd}] <<endl;
                break;
            }
            //비용 1 계산
            ll newx = cx+ cd;
            if(newx > K) continue;
            if(dist.count({newx,cd})== 0 || dist[{newx, cd}] > cnt+1){
                dist[{newx, cd}] = cnt+1;
                dq.push_back({newx, cd}); 
            }
            //비용 0 계산
            for(int i = 0 ;i < N ; ++i){
                ll newd = cd * v[i];
                if(newd + cx > K) continue;
                if(dist.count({cx, newd}) == 0 || dist[{cx, newd}] > cnt){
                    dist[{cx, newd}] = cnt;
                    dq.push_front({cx, newd});
                }
            }
            
        }
        #endif
        
#if 0
        /*
        사용 가능한 d 모두 만들기
        */
        
        queue<ll> q; 
        q.push(1); vt[1] = 1; candi.push_back(1);
        while(!q.empty()){
            ll cur = q.front();
            q.pop();
            for(int i =0 ; i< N ; ++i){
                ll newd= v[i]*cur;

                if(vt.count(newd) > 0) continue;
                if(newd > K) continue;

                q.emplace(newd);
                candi.emplace_back(newd);
                vt[newd] = 1;
            }
        }
        int sz = candi.size();
        queue<ll> qfwd, qbwd; //0에서 시작
        
        distbwd.clear(); distfwd.clear();
        qfwd.push(0);
        distfwd[0] = 0;
        qbwd.push(K);
        distbwd[K] = 0;
        int res = -1;

        while(!qfwd.empty() && !qbwd.empty()){
            //forward 탐색하기 중요한건 한 레벨만!!
            int fwdsize = qfwd.size();
            for(int i = 0;i < fwdsize ; ++i){
                ll curr= qfwd.front(); qfwd.pop();
                int currcnt= distfwd[curr];
                
                if(distbwd.count(curr)){
                    res = currcnt + distbwd[curr];
                    goto endloop;
                }
                
                for(int c =0 ;c < sz ; ++c){
                    ll nextx = curr+ candi[c];
                    if(nextx <= K && distfwd.find(nextx) == distfwd.end()){
                        distfwd[nextx] = currcnt +1;
                        qfwd.push(nextx);
                    }
                }
            }
            
            //backward 탐색하기
            int bwdsize = qbwd.size();
            for(int i = 0;i < bwdsize ; ++i){
                ll curr= qbwd.front(); qbwd.pop(); 
                int currcnt = distbwd[curr];

                if(distfwd.count(curr)){
                    res = currcnt + distfwd[curr];
                    goto endloop;
                }

                for(int c =0 ;c < sz ; ++c){
                    ll nextx = curr- candi[c];
                    if(nextx >=0 && distbwd.find(nextx)== distbwd.end()){
                        distbwd[nextx] = currcnt +1;
                        qbwd.push(nextx);
                    }
                }
            }
        }
        endloop:;
        cout <<"#" <<t<<" " <<res<<endl;
        #endif 
#if 0
        queue<State> q2;
        q2.emplace(State(0,0)); map[0] = 0;
        while(!q2.empty()){
            ll curx = q2.front().x; 
            ll curcnt = q2.front().cnt;
            q2.pop();
            if(curx == K){
                cout << "#" << t<< " " << curcnt <<endl;
                break;
            }

            for(int i = 0 ; i< sz ;++i){
                ll newx = curx+candi[i];
                if(newx <= K){
                    if((map.count(newx) == 0)){
                        map[{newx}] = curcnt+1;
                        q2.push(State(newx, curcnt+1));
                    }
                }
            }
        }
#endif
#if 0
        priority_queue<State, vector<State>, cmp> pq;
        pq.emplace(State(0, 0)); map[0] = 0;
        while(!pq.empty()){
            ll curx=pq.top().x;
            ll curcnt= pq.top().cnt; pq.pop();
            //cout << curx << " d: "<< curd <<" cnt:" <<curcnt <<endl;
            if(curx == K){
                cout << "#" << t<< " " << curcnt <<endl;
                break;
            }
            if (map.count({curx}) && curcnt > map.at({curx})) {
                continue;
            }

            for(int i = 0 ; i< sz ;++i){
                int newx = curx+candi[i];
                if(curx+candi[i] <= K){
                    if((map.count({newx}) == 0) || curcnt+1 < map[{newx}]){
                        map[{newx}] = curcnt+1;
                        pq.push(State(newx, curcnt+1));
                    }
                }
            }
        }
#endif
    }
    
    return 0;
}