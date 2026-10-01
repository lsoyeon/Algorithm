#include <string.h>
#include <vector>
#include <iostream>

using namespace std;
/*
n개 음이 아닌 정수, 정수들을 순서 바꾸지 않고 적절히 더하거나 빼서
numbers 2개 이상 20개 이하
target  1000이하
경우의 수 - dfs
*/
int dp[1000]; int len; int answer=0;
void dfs(vector<int>&  numbers, int target, int depth, int sum){
    //cout << "depth: " << depth<< " sum: " << sum <<endl;
    if(depth==len) {
        if(sum == target) {
            answer++;
        }
        return;
    }
    dfs(numbers, target, depth+1, sum+numbers[depth]);
    dfs(numbers, target, depth+1, sum-numbers[depth]);
}
int solution(vector<int> numbers, int target) {
    answer = 0;
    len = numbers.size();
    //memset(dp, 0, sizeof(dp));
    dfs(numbers, target, 0, 0);
    return answer;
}