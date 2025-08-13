#include <iostream>
#include <string>
#include <queue>
#define endl "\n"

using namespace std;
int N;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin>> T;
    for(int t = 1 ; t <= T ;++t){
        int a,b ;
        cin >> a >> b;
        queue<pair<int, string>> q;
        vector<int> vt(10000, 1);
        q.push({a,""}); vt[a] = 0;
        int d,s, l, r;
        while(!q.empty()){
            int cur = q.front().first;
            string str = q.front().second;
            q.pop();

            if(cur == b){
                cout <<  str<< endl;
                break;
            }
            
            d = (2*cur) % 10000;
            if(vt[d]) {
                q.push({d, str+"D"});
                vt[d]=0;
            }
            s = cur==0 ? 9999 : cur-1;
            if(vt[s]){
                q.push({s, str+"S"});
                vt[s] = 0;
            } 
            l = (cur%1000) *10 + cur/1000;
            if(vt[l]){
                q.push({l, str+"L"});
                vt[l]=0;
            }
            r = (cur%10)*1000 + cur/10;
            if(vt[r]){
                q.push({r, str+"R"});
                vt[r] =0;
            }
            
        }
    }
    
    return 0;
}