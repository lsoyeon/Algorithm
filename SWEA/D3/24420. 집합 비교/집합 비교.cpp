#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int T;
int size_a; //집합의 크기 = 1이상 50이하
int size_b;
/*
원소 개수 : 1~50
원소 크기 : 1~100
한 집합 내 모든 원소는 서로 다르다.
*/
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (int testcase = 0; testcase < T; ++testcase) {
        cin >> size_a >> size_b;
        set<int> a; int tmp;
        set<int> b;
        for (int i = 0; i < size_a; ++i) {
            cin >> tmp;
            a.insert(tmp);
        }
        for (int i = 0; i < size_b; ++i) {
            cin >> tmp;
            b.insert(tmp);
        }
        int flag = 1;
        if (size_a > size_b) {
            for (auto x : b) {
                if (a.find(x) == a.end()) {
                    cout << "?\n"; 
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout << ">\n";
            }
        }
        else if (size_a == size_b) {
            for (auto x : b) {
                if (a.find(x) == a.end()) {
                    cout << "?\n";
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout << "=\n";
            }
        }
        else {
            for (auto x : a) {
                if (b.find(x) == b.end()) {
                    cout << "?\n";
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout << "<\n";
            }
        }
    }
    return 0;
}