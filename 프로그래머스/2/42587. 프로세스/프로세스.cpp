#include <string>
#include <vector>
#include <queue>
using namespace std;
/*
실행 큐에서 대기중인 프로세스 꺼내기
큐에 대기중인 프로세스 중 우선순위 높은 프로세스 있으면 꺼낸 프로세스 큐에 넣기
없다면 방금 꺼낸 프로세스 실행
2 1 3 2
a b c d

c d a b


*/
typedef struct PRO{
    int num; 
    int pri;
}pro;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int, vector<int>> pq; //max-heap
    queue<pro> q;
    int len = priorities.size();
    for(int i = 0 ;i < len;++i){
        int p = priorities[i];
        pq.push(p);
        q.push({i,p});
    }
    int cnt = 0;
    while(!q.empty()){
        int cur_p = pq.top(); 
        while(!q.empty() && q.front().pri < cur_p){
            pro p = q.front(); q.pop(); q.push(p);
        }
        cnt++;
        pro p = q.front(); 
        if(p.num == location){
            return cnt;
        }
        pq.pop(); q.pop();
    }
    return answer;
}