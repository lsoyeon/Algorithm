#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
최소한의 객실만 사용, 예약손님 받기
한번 사용한 객실, 퇴실시간 기준으로 10분 청소 후 다음 손님
예약시각, 문자열 형태, book_time - 최대 1000명 , 시작시각 , 종료시각
필요한 최소 객실 수 return

먼저 입실 시간 빠른순으로 넣어야겠지?

근데 넣을 때 퇴실 시간 가장 빠른 객실 찾고,
만약 그 퇴실 시간이 내 입실 시간 보다 늦다면, 객실 추가
*/

int toMinute(const string &t){
    return stoi(t.substr(0,2)) * 60 + stoi(t.substr(3,2));
}

typedef struct REQ{
    int start;
    int end;
}Req;
bool sortCmp(const Req& r1, const Req& r2){
    return r1.start < r2.start;
}
int solution(vector<vector<string>> book_time) {
    int answer = 0;
    int sz = book_time.size();
    vector<Req> reserv;
    for(auto v : book_time ){
        reserv.push_back({toMinute(v[0]), toMinute(v[1])});
    }
    //입실시간 빠른순으로 정렬
    sort(reserv.begin(), reserv.end(), sortCmp);
    
    priority_queue<int, vector<int>, greater<int>> pq; //끝난 시각 적혀있는 현재 사용중인 방들
    for(Req r : reserv){
        if(pq.empty()){
            pq.push(r.end + 10);
        } else{
            int end_time = pq.top();
            if(end_time <= r.start ){
                pq.pop();
                pq.push(r.end + 10);
            } else{
                pq.push(r.end + 10);
            }
        }
    }
    
    return pq.size();
}