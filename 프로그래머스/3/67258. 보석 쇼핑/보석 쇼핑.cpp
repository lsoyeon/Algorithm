#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map <string, int> chk;
unordered_set<string> s;
/*
특정 범위 보석 모두 구매하되
진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 
가장 짧은 구간을 찾아서 구매
보열 배열 크기 : 10만개 이하

d r r d d e s d
*/
vector<string> arr;
vector<pair<int, int>> order;
    vector<int> answer;
    int sz = gems.size();
    
    arr.push_back(gems[0]);
    s.insert(gems[0]);
    order.push_back({0,0});
    
    //중간에 여러개 나오는 보석들 하나로 합쳐서 만들어두기
    for(int i = 1 ;i < sz ; ++i){
        if(gems[i-1]!= gems[i]){
            arr.push_back(gems[i]);
            order.push_back({i,i});
            s.insert(gems[i]);
        } 
        else {
            order[order.size()-1].second=i;
        }
    } 
    int cate_cnt = s.size();
    int min_len = sz+1;
    int arr_sz = arr.size();
    int l = 0; int r = 0;
    int cnt = 0;
    answer.push_back(0);
    answer.push_back(sz-1);
    //chk[arr[0]]++;
    //cout<< "cate_cnt: " << cate_cnt <<endl;
    if(cate_cnt == 1){
        answer[0]=1;
        answer[1]=1;
        return answer;
    }
    // for(int i = 0 ;i < arr_sz ; ++i){
    //     cout << arr[i] << " ";
    // } cout << endl;
    #if 1
    while(true){
        // 1. 여분 보석이 있으면 빼고 L 이동 (가장 우선순위!)
        if(l < arr_sz && chk[arr[l]] > 1){
            --chk[arr[l]]; 
            l++;
        } 
        // 2. 여분 보석이 없는데(chk == 1), 목표 보석을 다 모았다면 정답 갱신!
        else if (cnt == cate_cnt){
            int temp_l = order[l].second;
            int temp_r = order[r-1].first;
            int tmp = temp_r - temp_l + 1;
            
            if(min_len > tmp ){
                min_len = tmp;
                answer[0] = temp_l + 1;
                answer[1] = temp_r + 1;
            }
            
            // 정답을 기록했으니, 다음 구간 탐색을 위해 필수 보석 하나를 버리고 L 이동
            // (위 1번 조건에서 걸러졌으므로 여기서 chk[arr[l]]은 무조건 1입니다)
            --cnt; 
            --chk[arr[l]];
            l++;
        } 
        // 3. 목표 보석을 다 못 채웠는데 R이 끝까지 갔다면 탐색 종료
        else if (r == arr_sz){
            break;
        } 
        // 4. 보석이 부족하다면 R을 확장하며 보석 줍기
        else {
            if(chk[arr[r]] == 0){
                ++cnt;
            }
            ++chk[arr[r]];
            r++;
        }
    }
    #endif
    return answer;
}