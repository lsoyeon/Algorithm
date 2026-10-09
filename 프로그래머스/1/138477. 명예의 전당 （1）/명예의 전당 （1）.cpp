#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
//매일 1명의 가수 노래 부르고 시청자들 문자 투표 점수
//매일 출연 가수 점수 지금까지 출연 가수들의 점수 중 상위 k번째 이내
//해당 가수 점수 명예의 전당이라는 목록에 올려 기념.
vector<int> solution(int k, vector<int> score) {
    vector<int> answer; int sz = (int) score.size();
    vector<int> v;
    priority_queue<int, vector<int>> q;//max heap
    //상위 3개 중에 제일 낮은거...
    for(int i =0; i< sz ; ++i ){
        v.push_back(score[i]);
        sort(v.rbegin(), v.rend()); // 오름차순
        if(v.size()<k){
            answer.push_back(v.back());
        } else{
            answer.push_back(v[k-1]);
        }
    }
    return answer;
}