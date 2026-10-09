#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <locale>
using namespace std;
/*
파일 이름순 정렬 파일명 100글자 이내
영문 대소문자, 숫자, 공백, 마침표., 빼기부호 -
*/
typedef struct form{
    string h; int n; int idx;
}Form;
struct sort_cmp{
bool operator()(Form &f1 , Form&f2){
    if(f1.h != f2.h) return f1.h < f2.h; //오름차순
    if(f1.n != f2.n) return f1.n < f2.n;
    return f1.idx < f2.idx;
}};
vector<string> solution(vector<string> files) {
    vector<string> answer; int cnt = files.size();
    vector<string> tmp (cnt, ""); 
    //map<string, int> m; //key 중복 허용 안됨... 쓰려다가 말음
    vector<Form> v;
    for(int i =0 ; i < cnt ; ++i){
        #if 1
        string str = files[i]; 
        
        int find_idx=0 ; 
        char ch = str[find_idx];
        
        //숫자 찾기 - head, 숫자 착즙하기
        while(ch<'0' || ch > '9'){
            ch= str[++find_idx];
        }

        //cout << files[i][find_idx];
        //오류: string head = str.substr(0, find_idx-1);
        string head = str.substr(0, find_idx);
        //오류: tolower(head.begin(), head.end());
        for(auto &c : head){
            if(isupper(c)) c = tolower(c);
        }
        int num_start = find_idx;
        while(ch>='0' && ch <='9'){
            ch = str[++find_idx];
        }
        int num = stoi(str.substr(num_start, find_idx-num_start));
        #endif
        cout << "head: " << head<< "num: "<< num << endl;
        // 배열에 넣기(head,num , 인덱스 저장해두기)
        //string tmp = head + to_string(num);
        v.push_back({head, num, i});
        
    }
    //해당 배열 정렬하기
    //오류 sort(v.begin(), v.end(), sort_cmp)로 해서 오류 계속 났음.
    sort(v.begin(), v.end(), sort_cmp());
    //해당 배열 순인데 이제 인덱스 기존 배열이랑 엮어서 출력하기
    for(auto x : v){
        int idx = x.idx;
        answer.push_back(files[idx]);
    }
    return answer;
}