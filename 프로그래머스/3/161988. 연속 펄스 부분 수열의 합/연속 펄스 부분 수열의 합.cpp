#include <string>
#include <vector>
#include <algorithm>
#include <iostream> 
using namespace std;
long long dp1[500001];
long long dp2[500001];
// sequence_len은 배열 sequence의 길이입니다.
/*
연속 부분 수열 * 연속 펄스 부분 수열 (1, -1, 1 .. / -1, 1, -1 ..)

연속 펄스 부분 수열의 합 중 가장 큰 것 return하기
sequence 최대 길이 50만
원소의 값 -10만 ~ 10만

2 3 -6 1 3 -1 2 4
+ - + - + - + - +
- + - + - + - + -

2 3 -6 1 3 -1 2 4


dp1 : -2 +3 +6 +1 -3 -1 +2 -4
dp2 : +2 -3 -6 -1 +3 +1 -2 +4
- + - + - + - + -
*/
typedef long long ll;
ll p1 [500001];
ll p2 [500001];
int len;
long long solution(vector<int> sequence) {
    long long answer = 0;
    len = sequence.size();
    //cout << "len: " << len <<endl;
    for(int i =0 ;i < len ; ++i){
        //홀수
        if(i& 0x1){
            p1[i]= sequence[i];
            p2[i]= -sequence[i];
        }
        //짝수
        else{
            p1[i]= -sequence[i];
            p2[i]= sequence[i];
        }
    }
    /*
    누적합? dp?
    
    dp[i] = max(새로 시작 vs 현재까지의 배열 + arr[i]);
    */    
    ll maxSum = p1[0] > p2[0] ? p1[0] : p2[0];
    dp1[0]= p1[0]; dp2[0] = p2[0];
    //cout << "dp1[" << 0 << "]: " << dp1[0]<<endl;
    //cout << "dp2[" << 0 << "]: " << dp2[0]<<endl;
    for(int i = 1 ;i < len ; ++i){
        dp1[i] = max(dp1[i-1] + p1[i], p1[i]);
        dp2[i] = max(dp2[i-1] + p2[i], p2[i]);
        //cout << "dp1[" << i << "]: " << dp1[i]<<endl;
        //cout << "dp2[" << i << "]: " << dp2[i]<<endl;
        if(dp1[i]< dp2[i]) 
        {
            maxSum = max(maxSum, dp2[i]);
        } else {
            maxSum = max(maxSum, dp1[i]);
        }
    }
    
    answer = maxSum;
    return answer;
}