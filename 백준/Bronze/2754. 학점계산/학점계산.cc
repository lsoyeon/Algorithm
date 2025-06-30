#include <bitset>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	if (!str.compare("A0")) {
		cout << "4.0";
	}
	else if (!str.compare("A+")) {
		cout << "4.3";
	}
	else if (!str.compare("A-")) {
		cout << "3.7";
	}
	else if (!str.compare("B+")) {
		cout << "3.3";
	}
	else if (!str.compare("B-")) {
		cout << "2.7" ;
	}
	else if (!str.compare("B0")) {
		cout << "3.0";
	}
	else if (!str.compare("C+")) {
		cout << "2.3";
	}
	else if (!str.compare("C-")) {
		cout << "1.7";
	}
	else if (!str.compare("C0")) {
		cout << "2.0";
	}
	else if (!str.compare("D+")) {
		cout << "1.3";
	}
	else if (!str.compare("D-")) {
		cout << "0.7";
	}
	else if (!str.compare("D0")) {
		cout << "1.0";
	}
	else {
		cout << "0.0";
	}
}