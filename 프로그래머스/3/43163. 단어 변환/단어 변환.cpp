#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
/*
begin, target, words
begin -> target 가장 짧은 변환 과정
words 50개 이하
변환할 수 없는 경우 0 return
*/

unordered_map<string,int> vt;
unordered_map<string,int> dis;
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int sz= target.size();
    queue<string> q;
    q.push(begin);
    vt[begin]++;
    while(!q.empty()){
        string top = q.front();
        //vt[top]++;
        q.pop();
        if(top == target){
            return dis[top];
        }
        for(auto &w : words){
            if(vt.count(w) > 0){
               continue;
            }
            int cnt_diff =0 ;
            //int index_dff =0;
            for(int i = 0 ;i < sz ; ++i){
                if(w[i] != top[i]){
                    cnt_diff++;
                    //index_diff = i;
                }
            }
            if(cnt_diff ==1){
                q.push(w);
                dis[w]= dis[top]+1;
                vt[w]++;
            }
            
        }
    }
    return answer;
}