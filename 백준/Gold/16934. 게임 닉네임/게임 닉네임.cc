#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<string> used;
    unordered_map<string, int> counter;

    int N;
    cin >> N;

    while (N--) {
        string nick;
        cin >> nick;

        int &cnt = counter[nick];
        ++cnt;

        string alias;
        if (cnt == 1) {
            // 첫 등장: 가능한 접두사 찾기
            for (size_t len = 1; len <= nick.size(); ++len) {
                string pre = nick.substr(0, len);
                if (used.find(pre) == used.end()) {
                    alias = pre;
                    break;
                }
            }
            if (alias.empty()) alias = nick;
            // 접두사 전부 막기
            for (size_t len = 1; len <= nick.size(); ++len) {
                used.insert(nick.substr(0, len));
            }

        } else {

            alias = nick + to_string(cnt);
        }

        cout << alias << '\n';
    }

    return 0;
}
