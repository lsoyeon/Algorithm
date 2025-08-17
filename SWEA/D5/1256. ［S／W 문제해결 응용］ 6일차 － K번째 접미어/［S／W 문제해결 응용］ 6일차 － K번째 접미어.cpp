#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<string> suffixes;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int testCase = 1; testCase <= T; ++testCase) {
        int K;
        string S;
        cin >> K >> S; 
		suffixes.clear();
      
        int n = S.size();
        for (int i = 0; i < n; i++) {
            suffixes.emplace_back(S.substr(i));
        }
        sort(suffixes.begin(), suffixes.end());

        cout << "#" << testCase << " ";
        if (K > n) {
            cout << "none\n";
        } else {
            cout << suffixes[K - 1] << "\n";
        }
    }
    return 0;
}
