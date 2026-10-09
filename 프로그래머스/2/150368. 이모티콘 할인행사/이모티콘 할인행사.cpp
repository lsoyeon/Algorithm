#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
1.플러스 가입자 늘리기 
2.판매액 늘리기
n명 , m개 할인 판매(10, 20, 30, 40)
- 일정 비율 이상 할인 하는 이모티콘 모두 구매 -> lowerbound로 idx 찾고 합?(할인율 정렬 해야함)
- 이모티콘 구매 비용 합 >= 일정 가격 -> 구매 모두 취소... -> 부분홥?dp?

할인율 4개중 하나
이모티콘 개수 = m개 정가(100의 배수) < 10^6 (m은 7 이하)

가입자 최대 , 판매액 최대가 되는 경우 반환
[풀이] 완탐 가능할 것 같은데 각 이모티콘 마다 할인율 경우의 수 - 4^7 
*/
//중복 순열
int vt[8];
int max_reg =0; int max_sum=0;
int sales[4]={10,20,30,40};
void cal(const vector<int> &em_sales, const vector<int> emoticons, const vector<vector<int>> users){
    int reg =0; long long sum =0; //cout << em_sales[0] <<" " <<em_sales[1]<<endl;
    //오류: for(auto [ratio, price] : users){
    for(auto u : users){
        int ratio = u[0]; int price = u[1];
        int per_sum =0; 
        for(int i =0; i< em_sales.size(); ++i){
            if(ratio <= em_sales[i]) {
                per_sum += (emoticons[i] * (100-em_sales[i]));
                //cout << emoticons[i] << "*"<< 100-em_sales[i] <<"="<<per_sum <<" ";
            }
        }
        //cout << "\npersum: " << per_sum << "vs" << price <<endl;
        if(per_sum >= price) {
            reg++;
        } else{
            sum+= per_sum;
        }
    }
    //cout <<"reg: " << reg << " sum: "<<sum<<endl;
    if(max_reg < reg){
        max_reg = reg; max_sum = sum;
    } else if(max_reg == reg){
        if(max_sum < sum ){
            max_reg = reg; max_sum = sum;
        }
    }
}
void perm(int depth, 
           const vector<int>& emoticons, const vector<vector<int>>& users, 
          int k ,vector<int>& cur){
    if(depth == k){
        //for(auto x : cur) cout << x <<" ";
        //cout << endl;
        cal(cur, emoticons, users);
        return;
    }
    for(int i = 0 ; i < 4 ; ++i){
        cur.push_back(sales[i]);
        perm(depth+1, emoticons, users, k, cur);
        cur.pop_back();
    }
    return;
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer; 
    for(auto &x: emoticons){
        x/=100;
    }
    int len = emoticons.size();
    vector<int> cur;
    perm(0, emoticons, users, len,cur );
    answer.push_back(max_reg);
    answer.push_back(max_sum);
    return answer;
}