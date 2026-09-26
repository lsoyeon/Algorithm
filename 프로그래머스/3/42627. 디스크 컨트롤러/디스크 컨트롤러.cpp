#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
/*
하드디스크 - 하나의 작업
작업 번호, 요청시각, 소요시간 저장 - 대기큐

하드디스크 작업 X, 대기큐 비어있지 않다면X, 
-> 대기큐에서 우선순위 가장 높은 작업 꺼내서 하드디스크
1. 소요시간 짧은 것
2. 요청시각 빠른 것 
3. 작업 번호 작은 것

하드디스크 작업 마치는 시점, 요청 시점 겹치면
작업 마치자마자 요청 들어온 작업을 대기큐에 저장
우선순위 높은 작업 대기큐에서 꺼냄

모르겠다
*/
typedef struct JOB{
    int num;
    int start;
    int duration;

} job;
//sort함수는 pq랑 반대라서 
// return a > b; min heap
// return a > b; 내림차순(큰거부터)
bool compare(const job& j1, const job& j2){
    return j1.start < j2.start;
}
struct PQcompare{
    bool operator() (const job& j1, const job&j2){
        if(j1.duration  != j2. duration){
            return j1.duration > j2.duration;
        }
        if(j1.start != j2.start){
            return j1.start > j2.start;
        }
        return j1.num > j2.num;
    }
};

//요청 job
//이제 요청할 job: idx
//대기 큐 : pq
//현재 시각 : time
int solution(vector<vector<int>> jobs) {
    long long  answer = 0;
    int cnt = jobs.size();
    vector<job> v;
    for(int i = 0; i < cnt; ++i){
        v.push_back({i, jobs[i][0], jobs[i][1]});
    }
    //요청시간 빠른 순으로 정렬
    sort(v.begin(), v.end(), compare);
    priority_queue<job, vector<job>, PQcompare> pq;  
    int time =0;
    int idx = 0;
    while(idx < cnt || !pq.empty()){
        //현재 시간 전까지 들어갈 수 있는 요청 다 넣기
        while(idx < cnt && time >= v[idx].start){
            pq.push(v[idx]);
            idx++;
        }
        //대기 큐가 안 비었으면
        if(!pq.empty()){
            int cur_start = pq.top().start;
            int cur_duration = pq.top().duration; pq.pop();
            time += cur_duration;
            answer += (time - cur_start);
        } else if(idx < cnt){
            time = v[idx].start;
        }
    }
    answer /= cnt;
    return answer;
}