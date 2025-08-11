#include <iostream>
#define endl "\n"
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;
typedef pair<int, int> pii;
#define NMAX 101

int N, M;

int par[NMAX];

int find(int a){
    if(par[a]== a) return a;
    return par[a] = find(par[a]);
}
void un (int a, int b){
    int ra = find(a);
    int rb = find(b);
    par[ra] = rb;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

//	freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cout <<"#"<<test_case <<" ";
        cin>> N >> M;
        for(int i = 1 ;i <= N ; ++i){
            par[i] = i;
        }
        int a, b;
        for(int i = 0 ; i< M ; ++i){
            cin >> a >> b;
            un(a, b);
        }
        int ret =0;
        for(int i = 1 ; i<= N ; ++i){
            if(par[i]== i){
                ++ret;
            }
        }
        cout <<ret <<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}