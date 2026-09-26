#include <string>
#include <vector>

using namespace std;
/*
순서 바꾸지 않고 더하거나 빼서 타겟 넘버 만들기.
2개 이상 20개 이하
2^20
각 숫자 1~50, 타겟넘버 1000이하

상태: 현재 몇번째 숫자? , 현재 합 얼마
종료: 배열 끝 도달/합이 타겟 넘버와 같다면 카운트 증가
분기: 현재 숫자 더하기, 빼기
*/
int ans= 0;
void dfs(vector<int> &numbers, int target, int index, int csum){
    if(index == numbers.size()){
        if(target == csum){
            ans++;
        }
        return;
    }
    dfs(numbers, target, index+1, csum + numbers[index]);
    dfs(numbers, target, index+1, csum - numbers[index]);
    return;
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    dfs(numbers, target, 0, 0);
    answer = ans;
    return answer;
}