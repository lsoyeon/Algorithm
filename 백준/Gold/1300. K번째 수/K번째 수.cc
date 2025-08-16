#include <iostream>
#include <algorithm>
using namespace std;
#define endl "\n"
typedef long long ll;
ll N;
ll K; 
/*
k번째 수려면
자기자신보다 작거나 같은 숫자의 개수가 k개
각 행 순회
현재 탐색값보다 작거나 같은 수  
= min( 현재 탐색값 / 행, N);

1의 배수
2의 배수 
3의 배수 
...
N의 배수
*/
//m보다 작거나 같은 값들 개수

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    ll ans = 0;
    ll lo = 1;
    ll hi = K;
    while(lo <=hi){
        ll mid = lo + (hi-lo)/2;
        int cnt = 0;
        for(ll i = 1 ;i<= N ; ++i){
            cnt += min((mid/i), N);
        }
       // cout <<"left : " <<lo << " right : " << hi <<endl;
        // cout << "mid: " << mid << " cnt : " <<cnt <<endl;
        if(cnt >= K) {
            ans = mid;
            hi = mid-1;
        } else{
            lo = mid + 1;
        }
    }
    cout << ans<<endl;
    return 0;
}