#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    unordered_map<string, int> treeCount;
    string name;
    int total = 0;

    while (getline(cin, name)) {
        treeCount[name]++;
        total++;
    }

    vector<string> names;
    for (auto& pair : treeCount) {
        names.push_back(pair.first);
    }

    sort(names.begin(), names.end());

    cout << fixed << setprecision(4);
    for (const string& n : names) {
        double percent = (double)treeCount[n] * 100 / total;
        cout << n << " " << percent << "\n";
    }

    return 0;
}