#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
n명 입국심사, 각 입국 심삿관 심사 시ㅏㄴ 다름.
모든 심사대 비어있음.
모든 심사 받는 시간 최소
*/
typedef long long ll;
int n ;
vector <int> times;
int isPossible(ll mid){
    ll cnt =0;
    for(auto x : times){
       cnt += (mid / x); 
    }
    if(cnt == n ){
        return 0;
    } else if (cnt > n ){
        return 1;
    } else{
        return -1;
    }
}
long long solution(int _n, vector<int> _times) {
    long long answer = 0; n = _n;
    for(auto x: _times){
        times.emplace_back(x);
    }
    int k = times.size();
    long long max_time =(*min_element(times.begin(), times.end())) * (ll)n;
    ll l = 0; ll r = max_time; ll mid = 0; ll cnt =0;
    while(l < r){
        ll l1 = l/2;
        ll r1 = r/2;
        ll l_remain = l%2;
        ll r_remain = r%2;
        ll tmp = (l_remain+r_remain)/2;
        mid = l1+r1+tmp;
        //mid = (l+r)/2;
        cnt = 0;
        for(auto x : times){
            cnt += (mid / x); 
            if(cnt > n) {
                break;
            }
        }
        if(cnt >= n){
            r = mid;
        }else {
            l = mid+1;
        }
        cout << "mid: " << mid << " cnt : " << cnt << endl;
    }
    answer = l;
    return answer;
}