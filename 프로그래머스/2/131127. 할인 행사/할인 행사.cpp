#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
/*
xyz 일정한 금액 지불 - 10일 회원 자격 부여
xyz 마트에서 회원 대상 매일 한가지 제품을 할인 하는 행사
자신이 원하는 제품, 수량= 할인하는 날짜와 10일 연속으로 일치할 경우 회원가입
원하는 상품 want 배열
원하는 개수 number 배열
원하는 상품 최대 10개

discount 상품 개수 최대 100,000
-> 연속적으로 원하는 상품 총 개수 고정이니까 누적합?
0 1 2 3 4 5

*/
int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    int len=0;
    for(auto n : number){
        len += n;
    }
    int discount_len = discount.size();
    int max_st = discount_len - len + 1;
    unordered_map<string, int> um;
    for(int i =0 ; i < len ; ++i){
        um[discount[i]] ++;
    }

    bool ispossible = 1;
    for(int i =0 ;i < number.size() ; ++i){
        if(um[want[i]] < number[i]) {
            ispossible = 0;
            break;
        }
    }
    if(ispossible) answer ++;
    
    
    for(int st = 1; st< max_st ; ++st){
        //cout << st -1 << "빼고, " << st+len-1 <<endl;
        um[discount[st-1]]--;
        um[discount[st+len-1]]++;
        
        #if 1
        ispossible = 1;
        for(int i =0 ;i < number.size() ; ++i){
            if(um[want[i]] < number[i]) {
                ispossible = 0;
                break;
            }
        }
        if(ispossible) answer ++;
        #endif
    }
    
    return answer;
}