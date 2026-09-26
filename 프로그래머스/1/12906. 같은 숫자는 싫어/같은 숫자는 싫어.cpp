#include <vector>
#include <iostream>

using namespace std;
/*
숫자 0부터 9 배열 arr
연속적으로 나타나는 숫자는 하나만 남기고 전부 제거
제거도니 후 남은 수들 반환할때는 배열 원소 순서 유지
*/
vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int sz = arr.size();
    answer.push_back(arr[0]);
    for(int i = 1 ;i < sz ; ++i){
        if(arr[i-1]!=arr[i]) answer.push_back(arr[i]);
    }
    
    return answer;
}