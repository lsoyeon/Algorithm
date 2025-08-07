#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    deque<char> dq;
    for (char ch : str) {
        if (dq.empty()) {
            dq.push_back(ch);
            continue;
        }

        // 양쪽 비교 후 조건별 삽입 위치 결정
        if (ch >= dq.back() && ch >= dq.front()) {
            dq.push_back(ch);  // 가장 큰 경우는 뒤에
        } else if (ch <= dq.front()) {
            dq.push_front(ch);  // 앞보다 작거나 같으면 앞에
        } else {
            dq.push_back(ch);  // 그 외엔 그냥 뒤에
        }
    }

    for (char c : dq) cout << c;
    cout << '\n';
    return 0;
}
