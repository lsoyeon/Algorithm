#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

/*
입력이 2차원 배열로 주어져서, 나는 냅다 2차원 좌표라고 생각했다
근데, 빈칸의 위치마다 퍼즐의 모양이 다르고, 해당 퍼즐의 모양마다 최단 위치를 갱신하기 위해
dict[퍼즐모양] = 최소 횟수
key를 퍼즐모양으로 하기 위해서 퍼즐을 일차원화 시킨다!!
그리고, 퍼즐이 2차원 배열이지만 정렬을 해야하므로
'123456780'으로 정렬시킨다고 생각하자.

따라서, 1차원 문자열에서 0의 위치 --> 2차원 좌표로 변환 --> 이동여부 체크 --> 
이동시킬 수 있다면 새 위치 다시 1차원 배열로 --> 해당 위치로 0 이동

dictionary로 방문여부 체크하면서 bfs 진행!!
*/

/*
<string>
string s;
s.find('a') = 'a'가 위치해있는 인덱스 번호 반환
*/


int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

typedef struct POINT {
    int y;
    int x;
    POINT() { y = 0; x = 0; }
    POINT(int _y, int _x ) : y(_y), x(_x) {}
}Point;
Point dim1todim2(int idx) {
    Point ret;
    ret.y = idx / 3;
    ret.x = idx % 3;
    return ret;
}
int dim2todim1(Point p) {
    return p.y * 3 + p.x;
}
int isNotRange(Point p, int dir) {
    return ((p.y + dy[dir]) > 2 || (p.y + dy[dir] < 0) || (p.x + dx[dir] >2) || (p.x + dx[dir] < 0));
}

typedef struct HISTORY {
    string puzzle;
    int time;
    HISTORY(string p, int t) : puzzle(p), time(t) {}
}His;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "r", stdin);
    string str;
    string ans = "123456780";
    string input_s;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            // input 입력 받을 때 int를 char로 변환 후 string에 저장하기
            int num; cin >> num;
            char ch = num + '0';
            str = str + ch;
        }
    }

    queue <His> q;
    /*
    bfs로 완전탐색 할 때, 이미 지나간 곳은 pass해야하는 데
    여기서는 puzzle의 모양의 가지수가 너무 크므로 set 사용!
    set은 중복 불가, find 함수 사용 가능
    int 기존: bool visit[위치 구분]
    string 기준 : set <string> visit;
    */
    set <string> visit;

    q.push({ str, 0 });
    visit.emplace(str);
    
    while (!q.empty()) {
        string cur_puzzle = q.front().puzzle;
        int cur_zero_idx = cur_puzzle.find('0');
        Point cur_zero_p = dim1todim2(cur_zero_idx);
        int cur_time = q.front().time;
        q.pop();
        if (cur_puzzle == ans) {
            cout << cur_time << "\n";
            return 0;
        }

        for (int direction = 0; direction < 4; ++direction) {
            if (isNotRange(cur_zero_p, direction)) continue;
            
            Point new_zero_p = { cur_zero_p.y + dy[direction], cur_zero_p.x + dx[direction] };
            int new_zero_idx = dim2todim1(new_zero_p);
            string new_puzzle = cur_puzzle;
            swap(new_puzzle[cur_zero_idx], new_puzzle[new_zero_idx]);

            if (visit.find(new_puzzle) == visit.end()) {
                q.push({ new_puzzle, cur_time + 1 });
                visit.emplace(new_puzzle);
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}