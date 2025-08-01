#include <iostream>
#include <string>
using namespace std;



void process() {
    string s;
    cin >> s;

    int i = 0;
    bool valid = true;

    while (i < s.size() && valid) {
        if (s[i] == '0') {
            i++;
            if (i >= s.size() || s[i] != '1') {
                valid = false;
            }
            i++;
        } else if (s[i] == '1') {
            i++;
            int first_one = s.find('1', i);
            if (first_one == std::string::npos || first_one - i < 2) {
                valid = false;
                break;
            }

            int first_zero = s.find('0', first_one);
            if (first_zero == std::string::npos) {
                i = s.size();
                break;
            }

            if (first_zero == s.size() - 1) {
                valid = false;
                break;
            }

            i = first_zero;
            if (s[first_zero + 1] == '0' && (first_zero - first_one) > 1) {
                i--;
            }
        } else {
            valid = false;
        }
    }

    cout << (valid && i == s.size() ? "YES" : "NO") << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        process();
    }
}

