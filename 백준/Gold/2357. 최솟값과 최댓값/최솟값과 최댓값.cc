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
        tree[node] = v[s];
        return;
    }
    int mid = (s+e)/2;
    min_init(tree, s, mid, node*2);
    min_init(tree, mid+1, e, node*2+1);
    tree[node]= min(tree[node*2] , tree[node*2+1]);
}
void max_init(ll tree[], int s, int e, int node){
    if(s == e) {
        tree[node] = v[s];
        return;
    }
    int mid = (s+e)/2;
    max_init(tree, s, mid, node*2);
    max_init(tree, mid+1, e, node*2+1);
    tree[node]= max(tree[node*2] , tree[node*2+1]);
}
ll max_query(ll tree[], int node, int s, int e, int l, int r){

    if(l > e || r < s){
        return 0;
    } 
    if(l<=s && e<= r ){
        return tree[node];
    }
    int mid = (s+e)/2;
    ll lval = max_query(tree, node*2, s, mid, l , r);
    ll rval = max_query(tree, node*2 +1, mid+1, e, l ,r);
    return max(lval, rval);
}

ll min_query(ll tree[], int node, int s, int e, int l, int r){

    if(l > e || r < s){
        return 1000000001;
    } 
    if(l<=s && e<= r ){
        return tree[node];
    }
    int mid = (s+e)/2;
    ll lval = min_query(tree, node*2, s, mid, l , r);
    ll rval = min_query(tree, node*2 +1, mid+1, e, l ,r);
    return min(lval, rval);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i =0 ;i < N ; ++i){
        cin >> v[i];
    }
    min_init(mintree, 0, N-1, 1);
    max_init(maxtree, 0, N-1, 1);
    for(int i =0 ;i < M; ++i){
        int l , r; 
        cin >> l >> r;
        --l, --r;
        cout << min_query(mintree, 1, 0, N-1, l, r) <<" ";
        cout << max_query(maxtree, 1, 0, N-1, l, r) <<endl;
    }
    return 0;
}