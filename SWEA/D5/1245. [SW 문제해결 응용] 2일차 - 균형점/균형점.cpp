/*
n개 자성체 (x, y, z), 일직선
위치는 변하지 않음.
어떤 물체 --인력 --> 자성체 
인력 F = F = G*m1*m2/(d*d)
물체의 
왼쪽 인력 vs 오른쪽 인력 : 더 큰 쪽으로 물체 이동(같다면 정지 : 균형점)
좌표값 오차 : 1e-12보다 작아야한다. (double)

-> 결국 인력 = (자성체의 질량)/(거리제곱)
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define NMAX 11
#define diff (1e-13)
using namespace std;

int N; //자성체 개수 (2~10)

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
		vector<double> mass(N);
		vector<double> x(N);
		for (auto& pos : x) {
			cin >> pos;
		}
		for (auto& m : mass) {
			cin >> m;
		}
		cout << "#" << test_case << " ";
		for (int i = 0; i< N - 1; ++i) {
			double l = x[i]; double r = x[i + 1]; //l: 왼쪽 위치, r: 오른쪽 위치
			double mid = -1;
			while ((r-l) > diff) {
				double sum = 0;
				mid = ((double)l + (double)r) / 2;
				for (int left = 0; left<= i; ++left) {
					sum += mass[left] / pow((double)(mid - x[left]), 2);
				}
				for (int right = i + 1; right < N; ++right) {
					sum -= mass[right] / pow(double(x[right] - mid), 2);
				}
				//cout << sum << endl;
				if (sum > diff) { //왼쪽 힘이 더 세므로 오른쪽으로 이동
					l = mid;
				}
				else if (sum < -diff) { //오른쪽 힘이 더 세므로 왼쪽으로 이동
					r = mid;
				}
				else {
					break;
				}
			}
			printf("%.10f ", mid);
		}
		puts("");
	}
	return 0;
}