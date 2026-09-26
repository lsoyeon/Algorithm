#include <string.h>
#include <string>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
입차, 출차 기록
*/
int toMinute(string &t ){
    return 60*stoi(t.substr(0,2)) + stoi(t.substr(3,2));
}
int isOut[10000];
unordered_map<int, int> enter;
unordered_map<int, int> cal_fee;
unordered_map<int, int> cal_t;
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int basic_time = fees[0]; int basic_fee=fees[1]; double per_time = (double)fees[2]; int per_fee = fees[3];
    int len = records.size();
    //HH:MM_9999_IN

    fill(isOut , isOut +10000, -1);
    for(int i = 0 ;i < len ; ++i){
        string str = records[i];
        int num = stoi(str.substr(6,4));
        string state = str.substr(11);
        int time = toMinute(str);
        
        if(state == "IN"){
            isOut[num]=0;
            enter[num]=time;
        } else{
            isOut[num]=1;
            cal_t[num] += (time -enter[num]);
        }
    }
    for(int i = 0;i <= 9999; ++i){
        if(isOut[i] ==-1){
            continue;
        }
        else if(isOut[i]==0){
           cal_t[i] += (1439-enter[i]);
        }
        int cal = basic_fee;

        if(cal_t[i] > basic_time) {
            double dtmp = (cal_t[i]-basic_time)/per_time;
            cal += (ceil(dtmp) * per_fee);
        }
        answer.push_back(cal);
    }
    
    return answer;
}