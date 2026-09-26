#include <string>
#include <vector>

using namespace std;
/*
한며 ㅇ선수 제외하고 모두 마라톤 완주
마라톤 참여 선수 이름 배열 pariticipant, 
마라톤 완주 이름 배열 completion
완주하지 못한 선수의 이름
*/
#include <unordered_map> 

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> um;
    string answer = "";
    for(auto str : completion){
        um[str]++;
    }
    for(auto str : participant){
        if(um.count(str) == 0 || um[str]==0){
            return str;
        }
        um[str]--;
    }
    return answer;
}