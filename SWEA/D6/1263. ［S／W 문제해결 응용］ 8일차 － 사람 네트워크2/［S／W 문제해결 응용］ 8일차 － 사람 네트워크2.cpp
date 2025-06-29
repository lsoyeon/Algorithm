#include <stdio.h>
#include <time.h>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int main() {
    //time_t start = clock();
    //freopen("input.txt", "r", stdin);
    int tc, N;
    scanf("%d", &tc);

    for (int testCase = 1; testCase <= tc; testCase++) {
        scanf("%d", &N);
        vector<vector<int>> g(N);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int node;
                scanf("%d", &node);
                if (node) {
                    g[i].emplace_back(j);
                }
            }
        }
        int tempSum = 0;
        int minCC = INF;
        for (int i = 0; i < N; ++i) {
            vector<int> visited(N, 1);
            queue<pair<int, int>> q;
            tempSum = 0;
            q.emplace(i, 0);
            visited[i] = 0;
            while (!q.empty()) {
                
                auto u = q.front(); q.pop();
                for (auto temp : g[u.first]) {
                    if (visited[temp]) {
                        q.emplace(temp, u.second + 1);
                        visited[temp] = 0;
                        tempSum += u.second + 1;
                        if (tempSum >= minCC) { goto exit; }
                    }
                }
            }
        exit:

            if (tempSum < minCC) {
                minCC = tempSum;
            }

        }
        printf("#%d %d\n", testCase, minCC);
    }
   // time_t end = clock();
    //printf("time : %f\n", (double)(end - start));

    return 0;
}