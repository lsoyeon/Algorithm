#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        string p, arr_str;
        int n;
        cin >> p >> n >> arr_str;
        
        // 배열 파싱
        deque<int> deq;
        string num = "";
        int sz = arr_str.size()-1;
        for (int i = 1; i < sz; i++) {
            if (arr_str[i] == ',') {
                if (!num.empty()) {
                    deq.push_back(stoi(num));
                    num.clear();
                }
            } else {
                num += arr_str[i];
            }
        }
        if (!num.empty()) deq.push_back(stoi(num));
        
        bool is_front = true, error = false;
        for (char cmd : p) {
            if (cmd == 'R') {
                is_front = !is_front;
            } else { // cmd == 'D'
                if (deq.empty()) {
                    error = true;
                    break;
                }
                if (is_front) deq.pop_front();
                else deq.pop_back();
            }
        }
        if (error) {
            cout << "error"<<"\n";
        } else {
            cout << "[";
            if (!deq.empty()) {
                if (is_front) {
                    cout << deq.front();
                    deq.pop_front();
                    while (!deq.empty()) {
                        cout << "," << deq.front();
                        deq.pop_front();
                    }
                } else {
                    cout << deq.back();
                    deq.pop_back();
                    while (!deq.empty()) {
                        cout << "," << deq.back();
                        deq.pop_back();
                    }
                }
            }
            cout << "]"<<"\n";
        }
    }
    return 0;
}