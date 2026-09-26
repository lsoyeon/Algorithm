#include <string>
#include <vector>

using namespace std;
/*
열쇠 1 자물쇠 0 -> 다 채워줘야 함. 
열쇠 1 자물쇠 1 -> x
*/
int m ;
vector<vector<int>> rotate90 (vector<vector<int>> & key){
    vector<vector<int>> rot (m ,vector<int>(m,0));
    for(int i = 0;i < m ; ++i){
        for(int j = 0; j < m ; ++j){
            rot[j][m-1-i] = key[i][j];
        }
    }
    return rot;
}
int dy [4] = {-1, 1, 0, 0};
int dx [4] = {0, 0, -1, 1}; //상하좌우
// 2. 자물쇠의 모든 홈이 완벽하게 채워졌는지 확인하는 함수
bool check(const vector<vector<int>>& board, int n) {
    // 확장된 배열(board)의 정중앙에 위치한 원본 자물쇠 영역만 검사합니다.
    for (int i = n; i < n * 2; i++) {
        for (int j = n; j < n * 2; j++) {
            // 값이 1이 아니면 실패 
            // (0: 채워지지 않은 홈 존재, 2: 돌기끼리 부딪힘)
            if (board[i][j] != 1) { 
                return false;
            }
        }
    }
    return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true; int n = lock.size(); 
    m = key.size();
    int b_size = 3*n;
    vector<vector<int>> b(b_size, vector<int> (b_size, 0));
    for(int i = 0 ;i < n ; i++){
        for(int j = 0 ;j < n ;++j){
            b[i+n][j+n] = lock[i][j];
        }
    }
    for(int r = 0 ; r < 4; ++r){
        for(int i = 0 ; i < n *2; i++){
            for(int j = 0; j < n*2 ; j++){
                for(int x = 0 ;  x< m ;x++){
                    for(int y = 0 ; y< m ; ++y){
                        b[i+x][j+y] += key[x][y];
                    }
                }
                if(check(b, n)){
                    return true;
                }
                for(int x = 0 ;  x< m ;x++){
                    for(int y = 0 ; y < m; ++y){
                        b[i+x][j+y] -= key[x][y];
                    }
                }
            }
        }
        
        key = rotate90(key);
    }
    return false;
}