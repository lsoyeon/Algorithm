#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
/*
단품 -> 코스요리 형태 재구성
이전 각 손님들이 가장 많이 함께 주문한 단품 메뉴들
최소 2가지 이상 단품
최소 2명 이상의 손님으로부터 주문한 단품메뉴조합
손님 최대 20명, 각 손님 최대 주문 10, 단품메뉴 조합 요소 개수 최대 10
10C1 + 10C2 + ...10C10
중간에 반복 있을텐ㄷ;ㅔ..
*/
//조합
string path="1234567890";
vector<string> ORDERS;
int isPossible(string& menu, int meidx, int n){
    int sz = ORDERS.size(); int answer = 1;
    for(int i = 0;i < sz ; ++i ){ //사람들 중에
        if(i==meidx) continue;
        string other = ORDERS[i]; int flag =1;
        //cout <<"menu:"<< menu.substr(0,n)<<" Other:"<<other<<" ";
        for(int j = 0 ; j < n ; ++j){
            //만약 그 단품이 없으면
            //오류:if(find(other.begin(), other.end(), menu[j]) == other.end()){
            //cout << menu[j]<<"vs" << other<<"="<<other.find(menu[j]) <<endl;
            if(other.find(menu[j]) == string::npos){
                //오류 : int flag = 0으로 함!!!!!!!!!!!!!!!!
                flag =0; 
                break;
            }
        }
        //다른사람한테 해당 메뉴 있으니까 바로 true
        if(flag) {
            answer++;
        } 
    }
    //cout << "\n"<< menu.substr(0,n)<<"는 " << answer <<"번"<<endl;
    return answer;
}
unordered_map<string, int> chk;
vector<string> answer;
vector<pair<int, string>> v[11];//개수, 메뉴조합
void comb(int depth, int start, int k, string& order, int meidx){
    if(depth==k){
        //cout << path.substr(0,k)<< " "; return;
        #if 1
        if(chk.count(path) >0) return;
        chk[path]++;
        int cnt = isPossible(path,meidx, k);
        if(cnt > 1){
            if(v[k].empty()) {
                v[k].push_back({cnt, path.substr(0,k)}); return;
            }
            if(v[k][0].first < cnt) v[k].clear();
            if(v[k][0].first <= cnt){
                v[k].push_back({cnt, path.substr(0,k)});
            }
        }
        return;
        #endif
    }
    for(int i = start; i< order.size(); ++i){
        path[depth]=order[i];
        //처음에 comb(depth+1,start+1, k, order, meidx)로 해서 이상하게 함.
        comb(depth+1, i+1, k, order, meidx);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    //vector<string> answer;
    for(auto x : orders) ORDERS.push_back(x);
    for(int& n : course){
        //뽑아야할 메뉴 개수 : n
        //각 사람에서 n개만큼? 메뉴 조합 만들기 
        //(만약 해당 사람 먹은 메뉴 수가) n개보다 적으면 continue;
        for(int i = 0 ; i < orders.size(); ++i){
            string myorder = orders[i];
            int len = myorder.size();
            if(len < n) continue;
            //cout << "myorder: "<< myorder<<endl;
            sort(myorder.begin(), myorder.end());
            comb(0,0,n,myorder,i);
            //out << endl;
        }
        //해당 메뉴 조합이 다른 사람에게 있는지 확인하기
        //이미 이전에 만들었던 조합이면 패스
    }
    for(auto k: course){
        for(auto &x : v[k]){
            answer.push_back(x.second);
        }
    }
    sort(answer.begin(), answer.end()); //오름차순 정렬해서 리턴
    return answer;
}