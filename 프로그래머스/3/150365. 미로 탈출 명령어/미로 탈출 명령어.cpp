#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
//dlru 하 좌 우 상
int dy [4] = {0, -1, +1, 0}; //col
int dx [4] = {+1, 0, 0, -1}; //row
unordered_map<int, char> um;
char dir_dict [4] = {'d', 'l', 'r', 'u'};

/*
(x,y) -> (r,c)
이동 거리 k 
같은 격자 두번 이상 방문 가능. (r,c) 에 도착해도 이동거리 다 못 채웠으면 또 다른 곳 다녀와도 됨.
*/
//1-based 미로
/*
종료 : 거리 =k

*/
int N, M;
string ans;
bool found = false;
void dfs(int cx, int cy, int cd, int r, int c, int k, string &path){
    if(found) return;
    int remain_dist = abs(r-cx) + abs(c - cy);
    int remain_steps = k - cd;
    if(remain_dist > remain_steps || (remain_steps - remain_dist) %2 == 1) return;
    
    if(cd == k){
       if(cy == c && cx == r){
        found = true;
        ans = path;
        return;
       }
    }
    
    for(int dir = 0 ;dir < 4 ; ++dir){
        int ny = cy + dy[dir];
        int nx = cx + dx[dir];
        if(ny > M || ny < 1 || nx > N || nx < 1) continue;
        path.push_back(um[dir]);
        dfs(nx, ny, cd+1, r, c, k, path);
        path.pop_back(); 
    }
}
string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    N = n; M = m; 
    um[0]='d'; um[1]='l'; um[2]='r'; um[3]='u';
    //격자 크기 n*m
    //50이하, k 이동거리 - 2500 이하
    int D = abs(x-r)+ abs(y-c);
    if(D > k || (k-D)%2 == 1) {
        return "impossible";
    }
    dfs(x, y, 0, r, c, k, answer);
    answer = ans;
    return answer;
}