#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Pos {
    int x, y;
};

int getDist(const Pos &a, const Pos &b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<Pos> places(n + 2); // 0: 집, 1~n: 편의점, n+1: 페스티벌
        for (int i = 0; i < n + 2; ++i) {
            cin >> places[i].x >> places[i].y;
        }

        vector<bool> visited(n + 2, false);
        queue<int> q;

        q.push(0);
        visited[0] = true;

        bool reachable = false;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            if (cur == n + 1) {
                reachable = true;
                break;
            }
            for (int i = 0; i < n + 2; ++i) {
                if (!visited[i] && getDist(places[cur], places[i]) <= 1000) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        cout << (reachable ? "happy" : "sad") << '\n';
    }

    return 0;
}