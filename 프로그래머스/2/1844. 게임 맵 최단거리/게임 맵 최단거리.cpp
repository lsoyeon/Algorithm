#include<vector>
#include <iostream>
#include <queue>
using namespace std;
/*
상대 팀 진영 먼저 파괴하면 이기기
상대 진영 최대한 빨리 도착 유리
*/ typedef pair<int,int> pii;
int n, m ; 
int dx [4] = {-1, 1, 0, 0};
int dy [4]= {0, 0, 1, -1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    cout << "n: " << n << " m : " << m <<endl;
    queue<pair<pii, int>> q;
    q.push({{0,0}, 1}); maps[0][0] =0;
    while(!q.empty()){
        int cy = q.front().first.first;
        int cx = q.front().first.second;
        int dis = q.front().second; q.pop();
        if(cy == n-1 && cx == m-1) return dis;
        
        for(int d = 0 ; d< 4 ; ++d){
        int nx = cx + dx[d]; int ny = cy + dy[d];
        if(nx < 0 || nx > m-1 || ny < 0 || ny > n-1){
            continue;
        }
        if(maps[ny][nx]){
            maps[ny][nx] = 0;
            q.push({{ny,nx}, dis+1});
        }
        
    }
    }
    return -1;
}