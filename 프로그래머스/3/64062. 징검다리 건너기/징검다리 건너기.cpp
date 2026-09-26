#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
/*
니니즈 친구들, 라이언 선생님
왼쪽에서 징검다리통해 오른쪽으로 건너기
니니즈 친구들은 한번에 한명씩 건너기, 한 친구 모두 건넌 뒤 다음 사람 건너기
- 징검다리 일렬, 디딤돌 모두 숫자 적혀짐, 디딤돌 숫자 밟을 때마다 1씩 줄어듦
- 디딤돌 숫자 0이 되면 밟을 수 없고, 다음 디딤돌로 한번에 여러칸 건너뛰기
- 다음으로 밟을 수 있는 디딤돌 여러개이면 가까운 디딤돌로 건너뛰기

디딤돌 적힌 숫자가 순서대로 담긴 배열 stones (20만 이하)
한번에 건너 뛸 수 있는 디딤돌의 최대 칸수 k

구: 최대 몇 명 까지 징검다리를 건널 수 있는가
*/
vector<int> s;
int solution(vector<int> stones, int k) {
    int answer = 0;
    int low = 0;
    int high = *max_element(stones.begin(), stones.end());
    int mid=0; int cnt = 0; 
    int len = stones.size();
    while(low <= high){
        mid = (low+high)/2;
        int max_cnt = 0;
        cnt = 0;
        //cout << "stones"<<endl;
        for(int i = 0;i < len ; ++i){
            int t = stones[i]-mid;
            //cout << t <<" ";
            if(t < 0){
                ++cnt;
            } else{
                if(max_cnt < cnt ) max_cnt = cnt;
                cnt= 0;
            }
        } //cout << endl;
        //cout << "mid: " << mid << "max_cnt : " << max_cnt << endl;
        max_cnt = max(max_cnt, cnt);
        ++max_cnt;
        if(max_cnt > k){
            high = mid - 1;
        }
        else{
            answer = mid;
            low = mid +1;
        }
    }
    return answer;
}