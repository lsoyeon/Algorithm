#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <map>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
과제 시작하기로 한 시각 - 시작
새로운 과제 시작할 시각 - 기존 진행중이던 과제 있다면 멈추고 새로 시작
진행중이던 과제 끝내면 멈췄던 ㅓ과제 이어서 하기
멈춘 과제 여러개면 가장 최근 과제부터 시작... -> stack?

name, start, playtime
start 00:00 
*/
int cal_time (const string t){
   int hour = 60 * stoi(t.substr(0, 2)) ;
    int min = stoi(t.substr(3, 2));
    //cout <<t  << endl;
    return hour + min;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int cnt = plans.size();
    map<string, int> start;
    //cout << plans[0][0]<<endl;

    for(int i = 0;i < cnt ; ++i){
        start[plans[i][1]] = i;
    }
    int check_cnt = 0;
    stack<int> stopped;
    for(auto it = start.begin(); it != start.end(); ++it){
        int cur = cal_time(it->first);
        int left = stoi(plans[it->second][2]);
        //cout << cur << " "<<left;
        if(check_cnt == cnt -1){
            answer.push_back(plans[it->second][0]);
            while(!stopped.empty()){
                answer.push_back(plans[stopped.top()][0]);
                stopped.pop();
            }
            break;
        }
        if(1){
            check_cnt ++;
            int nxt = cal_time(next(it)-> first);
            
            
            //딱 맞게 끝난 경우
            if(cur + left == nxt){
                answer.push_back(plans[it->second][0]);
                cur += left; //진행중이던 과제 끝내고 바로 새로운 과제 있다면 바로 시작해야함.
            }
            //다음 과제 까지 시간 남은 경우
            else if(cur + left < nxt){
                answer.push_back(plans[it->second][0]);
                cur += left; //진행중이던 과제 끝내고 아직 시간 남았으니까 멈췄던 과제 하기
                while(!stopped.empty()){
                    int idx = stopped.top();
                    int dur = stoi(plans[idx][2]);
                    if(cur + dur == nxt){
                        stopped.pop();
                        answer.push_back(plans[idx][0]);
                        cur += dur;
                        break;
                    } else if (cur + dur < nxt){
                        stopped.pop();
                        answer.push_back(plans[idx][0]);
                        cur += dur;
                    } else {
                        int tmp = dur - (nxt - cur);
                        plans[idx][2]= to_string(tmp);
                        break;
                    }
                }
                
            }
            //다음 과제를 먼저 시작해야하는 경우
            else{
                stopped.push(it->second); //index로 저장
                int tmp = left - (nxt - cur);// 남은 시간 계산
                plans[it->second][2]= to_string(tmp);
            }
        }

    }

    
    return answer;
}