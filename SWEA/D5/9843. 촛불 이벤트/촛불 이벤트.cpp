#include<iostream>
#include <cmath>
using namespace std;
#define endl "\n"
typedef long long ll;
ll N;
/*
x(x+1)/2 = N 인 x 찾기
x(x+1) = 2*N
x^2 < 2*N

left = 0, right = sqrt(2N)
*/
int main(int argc, char** argv)
{
	ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0); int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> N;
        cout << "#"<<test_case<<" ";
        ll doubleN = N*2;
        ll left = 0; ll right = sqrt(doubleN);
        ll mid, ans=0;
        while(left <= right){
            mid = left + (right-left)/2;
            //cout << left <<" " <<right << " mid: " << mid<< endl;
            if(mid*(mid+1) == doubleN){
                ans = mid;
                break;
            }

            else if( mid*(mid*1) < doubleN) {
                //ans = mid;
                left = mid+1;
            }
            else {
                //ans = mid;
                right = mid-1;
            }
        }
        if(ans == 0){
            cout << -1<<endl;
        } else{
            cout << ans <<endl;
        }
	}  
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}