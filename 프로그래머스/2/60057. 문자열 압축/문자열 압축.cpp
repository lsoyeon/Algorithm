#include <string>
#include <vector>
#include <iostream>
using namespace std;
/*
가장 짧은 압축 방법 찾기
s 길이 1000 이하
*/
int solution(string s) {
    int len = s.size(); int answer = len;
    int half_len = (len)/2;
    for(int i =1; i<= half_len ; ++i){
        int cnt = (len) / i; //i개 단위로 나눠을 때 
        string tmp = "";
        string prev = s.substr(0,i); //0번째
        for(int k = 1 ; k < cnt ;){
            int duplicate_cnt = 1;
            while(1){
                string cur = s.substr(k*i, i);
                //cout << "prev: " << prev << " cur: "<< cur<< " k: " << k << endl;
                if(prev==cur) {
                    duplicate_cnt++;
                    k++;
                    if(k == cnt) {
                        tmp+=to_string(duplicate_cnt);
                        tmp+=prev;
                        break;
                    }
                } else{
                    if(duplicate_cnt == 1){
                        tmp +=prev;
                    } else{
                        tmp+= to_string(duplicate_cnt);
                        tmp+= prev;
                    }
                    prev = cur;
                    k++;
                    if(k == cnt){
                        tmp += cur;
                    }
                    break;
                }
            }
        }
        if(len %i != 0){
            tmp += s.substr(i*cnt);
        }
        //cout << i<<"단위로 자른 tmp: " << tmp <<" size: " << tmp.size()<<endl;
        if(answer > tmp.size()){
            answer = tmp.size();
        }
        
        
    }
    return answer;
}