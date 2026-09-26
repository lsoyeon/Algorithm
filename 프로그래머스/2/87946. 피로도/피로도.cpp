#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
/*
일정 피로도 사용해서 던전 탐험 가능
각 던전마다
- 탐험 시작 : 최소 필요 피로도 >= 현재 남은 피로도
- 탐험 마침 : 소모 피로도

탐험 가능한 최대 던전 수
현재 피로도 k, 각 던전별 최소 필요 피로도, 소모피로도
던전 개수 최대 8개

8! 
순열
*/
int answer = -1;
int dungeons_cnt;
bool vt[9];
void dfs(int cnt, int cur_piro, vector<vector<int>> & dungeons){
    answer = max(answer, cnt);
    
    for(int i = 0; i < dungeons_cnt; ++i){
        if(vt[i]) continue;
        
        if(cur_piro >= dungeons[i][0]){
            vt[i]=1;
            dfs(cnt+1, cur_piro-dungeons[i][1], dungeons);
            vt[i]=0;
        }
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    memset(vt, 0, sizeof(vt));
    dungeons_cnt = dungeons.size();
    dfs(0, k, dungeons);
    return answer;
}