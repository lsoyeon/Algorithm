#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std; typedef long long ll;
/*ㅎ피로도 - 야근 시작 시점 - 남은 일의 작업량^2
N시간 동안 야근 피로도 최소화 
1시간 동안 작업량 1만큼 처리 가능
퇴근까지 남은 N시간 
4, 3, 3 -> -4  평균 2
정렬) 3 3 4 , 평균 초과 인덱스 0
2 1 1

2 1 2 -> -1  평균 1
정렬) 1 1 2, 평균 초과 인덱스 2

1 8 9 -> -3 평균 5
정렬) 1 8 9, 평균 초과 인덱스 1
1 8 6 ? 64 36 1
1 7 7 ? 49 49 
평균 초과 한 숫자들? 최대한 숫자 균등하게 맞추는게 좋음...?

8, 1, 1
4 빼면 평균 2
4 1 1 -- 2 1 1
6 0 0 -- 

편차가 큰 거 부터 
*/

long long solution(int n, vector<int> works) {
    long long answer = 0; int len = works.size();
    ll sum = 0; 
    priority_queue<ll> pq;
    for(auto x : works) { sum += x; pq.push(x);}
    if(sum - n < 1) return 0 ;
    sum = 0;
    while(n > 0){
        int maxnum = pq.top();
        pq.pop(); pq.push(maxnum-1); n--;
    }
    while(!pq.empty()){
        int n = pq.top(); pq.pop();
        sum += n * n;
    }
    return sum;
}