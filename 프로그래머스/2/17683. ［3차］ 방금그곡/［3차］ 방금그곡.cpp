#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>
using namespace std;
/*
음악 처음 이어질수도(반복재생)
끊을 경우 원본음악에 들어있다해도 그 곡 아닐 수도 있음...

음악제목, 재생시작, 끝, 악보
C, C#, D, D#, E, F, F#, G, G#, A, A#, B -  1분에 1개 총 12 -> 현재시간 나머지로 인덱스 계산해서 접근
음악길이 < 재생길이 - 반복재생 / 짧으면 재생길이만큼만 재생
자정 넘지 않음
조건 일치 음악 여러개이면 재생된 시간이 제일 긴 음악 -> 먼저 입력된 음악
없으면 (None)
[풀이]
곡 100개 이하, 기억음 1439개 이하
각 곡마다 -> 해당 재생시간 동안에 나온 음 총 문자열 만들기 -> 해당 문자열에 기억음문자열이 들어있는지 find함수로 찾기
-> 있으면, 재생길이, 입력 시간, 제목 구하고 pq에 넣기
*/
int caltime(const string& t){
    return 60*stoi(t.substr(0,2)) + stoi(t.substr(3,2));
}
string change(const string& music){
    string ans = ""; int len = music.size();
    for(int i = 0;i < len; ++i){
        if(i==len-1) {ans+= music[i]; break;}
        if(music[i+1] == '#'){
            ans += tolower(music[i]);
            i++;
        } else{
            ans+= music[i];
        }
    }
    return ans;
}
int minst=987654321; int maxdur = 0;
string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    string remem = change(m);
    for(auto i : musicinfos){
        int st = caltime(i);
        int dur = caltime(i.substr(6)) - st;
        int idx = 12; while(i[idx]!= ',') ++idx;
        string name = i.substr(12, idx-12); cout << "name: "<<name<<endl;
        string music = change(i.substr(idx+1)); int musiclen = music.size();
        int mok = dur/musiclen; int remain = dur%musiclen;
        string played="";
        for(int r = 0 ; r< mok ; ++r) played += music;
        played += music.substr(0, remain);
        //오류: string played = mok * music + music.substr(0, remain);
        //if(find(played.begin(), played.end(), remem) != played.end() ){
        if(played.find(remem) != string::npos){
            if(maxdur < dur){
                answer = name;
                maxdur= dur; minst = st;
            } else if (maxdur== dur){
                if(minst > st){
                    answer = name;maxdur= dur; minst = st;
                }
            }
        }
    }
    return answer;
}