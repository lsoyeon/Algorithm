#include <iostream>
#include <string>
#include <queue>
#define endl "\n"
using namespace std;
typedef long long ll;
#define NMAX 100000
int N, M;
ll mintree[NMAX*4];
ll maxtree[NMAX*4];
ll v[NMAX];
void min_init(ll tree[], int s, int e, int node){
    if(s == e) {
        tree[node] = s;
        return;
    }
    int mid = (s+e)/2;
    min_init(tree, s, mid, node*2);
    min_init(tree, mid+1, e, node*2+1);
    if(v[tree[node*2]] <= v[tree[node*2+1]]){
        tree[node] = tree[node*2];
    }
    else tree[node] = tree[node*2+1];
}
//idx번째 수 val로 변경
void update(int node, int s, int e,int idx, ll val){
    //갱신할 인덱스가 범위 벗어나면 무시
    if(idx < s || e < idx) return ;
    //리프노드 도달하면 종료
    if(s==e) return;
    
    int mid = (s+e)/2;
    if(s!=e){
        update(node*2, s, mid, idx, val);
        update(node*2+1, mid+1, e , idx, val);
    }
    if(v[mintree[node*2]] <= v[mintree[node*2+1]] ){
        mintree[node] = mintree[node*2];
    } else{
        mintree[node] = mintree[node*2+1];
    }
}
ll min_query(ll tree[], int node, int s, int e, int l, int r){

    if(l > e || r < s){
        return -1;
    } 
    if(l<=s && e<= r ){
        return tree[node];
    }
    int mid = (s+e)/2;
    ll lidx = min_query(tree, node*2, s, mid, l , r);
    ll ridx = min_query(tree, node*2 +1, mid+1, e, l ,r);
    if(lidx ==-1){
        return ridx;
    }
    if(ridx==-1){
        return lidx;
    }
    return v[lidx] <= v[ridx] ? lidx : ridx;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("input.txt","r", stdin);
    cin >> N ;
    for(int i =0 ;i < N ; ++i){
        cin >> v[i];
    }
    min_init(mintree, 0, N-1, 1);
    cin >> M;
    for(int i =0 ;i < M; ++i){
       int tmp ; cin >> tmp;
       if(tmp==1){
            int idx; ll val; cin >> idx >> val;
            v[--idx]= val;
            update(1, 0, N-1, idx, val);
       } else{
            int l, r; cin >> l >>r;
            cout << min_query(mintree, 1, 0, N-1, --l, --r)+1 <<endl;
       }
    }
    return 0;
}