#include <string>
#include <vector>
#include <stack>
#include <unordered_map> 
#include <bitset>
#include <set>
#include <iostream>
using namespace std;
typedef pair<int, vector<int>> piv;
int userlen[8];
int bannedlen[8];
unordered_map <int, vector<int>> um; //key : banned_id, value : <cnt, user_ids>
int chk_banned_id[8];
int chk_user_id[8];
int N, M;
set<int> res;

void dfs (int state, int banned_idx, int cnt){
    if(cnt == M){
        res.insert(state);
        return;
    }
    
    for(auto x : um[banned_idx]){
        if(state & (1 << x)){
            continue;
        }
        else {
            int new_state = state | (1<<x);
            dfs(new_state, banned_idx+1, cnt+1 );
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {
    int answer;
    M = banned_id.size();
    N = user_id.size();
    for(int i = 0 ;i < M ; ++i){
        bannedlen[i] = banned_id[i].length();
    }
    for(int i = 0 ;i < N ; ++i){
        userlen[i] = user_id[i].length();
    }
    
    for (int i = 0 ;i < M; ++i) {
        int banlen = bannedlen[i];
        for(int j = 0; j < N; ++j){
            int ulen = userlen[j];
            if(banlen != ulen){
                continue;
            }
            int isSimilar=1;
            for(int k = 0 ;k < ulen ; ++k){
                if((banned_id[i][k]!='*') && (banned_id[i][k] != user_id[j][k])){
                    isSimilar= 0;
                    break;
                }
            }
            if(isSimilar){
                um[i].push_back(j); //user id idx 추가
            }
        }
    }
    
    dfs(0, 0, 0);
    answer = res.size();
    return answer;
}