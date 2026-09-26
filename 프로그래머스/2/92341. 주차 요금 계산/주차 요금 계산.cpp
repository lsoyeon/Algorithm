#include <string.h>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;
//차량 번호가 작은 자동차부터 청구할 주차 요금 
vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int rec_cnt = records.size();
    unordered_map <int, pair<int, int>> um;
    vector<int> cars;
    int isOut[10000] = {0,};
    int sum [10000] = {0,};
    int charge = 0;
    //시각(HH:MM), 차량번호(4자리), 내역(IN / OUT)
    for(string s : records){
        int hour = stoi(s.substr(0,2));
        int minute =stoi(s.substr(3,2));
        int num = stoi(s.substr(6,4));
        string state = s.substr(11);
        
        
        if((state== "IN")){ //strcmp 왜 안됨?
            if(um.count(num) == 0) {
                cars.push_back(num);
            }
            um[num]={hour, minute};
            isOut[num] = 0;
            //cout << state;
        } else {
            int enter_hour = um[num].first;
            int enter_minute= um[num].second;
            int elapsed = 0;
            if(enter_minute > minute){
                elapsed += minute + 60 - enter_minute;
                --hour;
            } else{
                elapsed += minute - enter_minute;
            }
            elapsed += 60*(hour-enter_hour);
            sum[num] += elapsed;
            cout << "sum[num]: "<< sum[num] <<endl;
            isOut[num] =1;
        }
    }
    sort(cars.begin(), cars.end());
        
    for (auto num : cars){
        int elapsed = sum[num];
        if(isOut[num]==0){
            int hour = 23; int minute= 59;
            int enter_hour = um[num].first;
            int enter_minute= um[num].second;
            charge = fees[1];
            elapsed += minute - enter_minute;
            elapsed += 60*(hour-enter_hour);
        }
        cout << "elapsed: "<<elapsed <<endl;
        charge = fees[1];
        if(elapsed > fees[0]){
            elapsed -=fees[0];
            if(elapsed % fees[2] == 0){
                charge += (elapsed / fees[2]) * fees[3];
            }
            else {
                charge += (elapsed / fees[2]+1) * fees[3];
            }
        }
        answer.push_back(charge);
    }
        
    return answer;
}