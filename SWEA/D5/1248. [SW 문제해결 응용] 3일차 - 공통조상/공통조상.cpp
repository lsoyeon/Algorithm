#include<iostream>
#define VMAX 10001
#include <queue>
using namespace std;
//가장 가까운 공통 조상의 번호
// 그것을 루트로 하는 서브트리의 크기
int V, E, a, b, par, son, root;
int arr[VMAX][4]; //left , right, par, height
void dfs(int n, int h) {
	if (n == 0) return;
	arr[n][3] = h;
	dfs(arr[n][0], h + 1);
	dfs(arr[n][1], h + 1);
}
void print() {
#if 1
	for (int i = 1;i <= V;++i) {
		cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << " " << arr[i][3] << endl;
	}
#endif 
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		fill(&arr[0][0], &arr[V][3], 0);
		cin >> V >> E >> a >> b;
		for (int i = 0;i < E; ++i) {
			cin >> par >> son;
			//만약 왼쪽 자식이 비어있으면
			if (!arr[par][0]) {
				arr[par][0] = son;
			}
			else {
				arr[par][1] = son;
			}
			arr[son][2] = par;
		}


		/*
		-1. root 계산하기
		0. dfs로 높이 다 계산
		1. a와 b의 높이가 같은 노드가 될 때까지 반복
		2-1. 만약 같다면 subtree 노드 계산(bfs?)
		2-2. 다르다면, 같을 때까지 위로 올라가기
		*/
		//b의 높이가 더 깊은 경우
		for (int i = 1; i <= V; ++i) {
			if (!arr[i][2]) {
				root = i;
				break;
			}
		}
		//cout << "root: " << root << endl;
		arr[root][3] = 0; //root의 height는 0
		dfs(root, 0);
		//print();
		int ha = arr[a][3];
		int hb = arr[b][3];

		if (ha < hb) {
			while (ha != arr[b][3]) {

				b = arr[b][2]; //부모로 올라가기
			}
		}
		//a의 높이가 더 깊은 경우
		else if (ha > hb) {
			while (hb != arr[a][3]) {
				a = arr[a][2]; //부모로 올라가기
			}
		}
		//cout << "a: " << a << "b: " << b << endl;
		while (a != b) {
			a = arr[a][2];
			b = arr[b][2];
		}
		cout << "#" << test_case << " " << a << " ";
		//subtree 노드 계산
		int cnt=0;
		queue <int> q;
		q.emplace(a);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			cnt++;
			int l = arr[cur][0];
			int r = arr[cur][1];
			if (l > 0) {
				q.emplace(l);
				if (r > 0) {
					q.emplace(r);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}