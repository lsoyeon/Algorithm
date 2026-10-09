#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string,int> cnt;
void comb(int start, int n, const string& order, string& cur){
    if(cur.size()==n){
        cout << cur<<" ";
        cnt[cur]++; return;
    }
    
    for(int i = start ; i < order.size() ; ++i){
        cur.push_back(order[i]);
        //또 실수함!!!!!!!!! comb(start+1, n, order, cur);
        comb(i+1, n, order, cur);
        cur.pop_back();
    }
    return;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(auto &n : course){
        for(auto o : orders){
            if(o.size() < n ) continue;
            sort(o.begin(), o.end());
            string cur;
            cout <<"myorder: "<<o <<endl;
            comb(0,n,o, cur);
            cout <<endl;
        }
        int maxcnt = 1;
        for(auto[menu, c]: cnt){
            maxcnt = max(maxcnt, c);
        }
        if(maxcnt==1) continue;
        for(auto[menu, c]: cnt){
            if(c == maxcnt) answer.push_back(menu);
        }
        cnt.clear();
    }
    sort(answer.begin(), answer.end());
    return answer;
}