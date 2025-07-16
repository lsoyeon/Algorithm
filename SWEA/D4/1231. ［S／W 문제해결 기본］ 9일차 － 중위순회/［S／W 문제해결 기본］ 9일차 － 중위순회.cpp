#include <iostream>
using namespace std;

int total;

struct Tree {
	Tree* l;
	Tree* r;
	char ch;
	int idx;
};

const int LIMIT = 1000;
Tree memory[LIMIT];
int memIdx = 0;

Tree* create(int idx, char ch) {
	memory[memIdx].idx = idx;
	memory[memIdx].ch = ch;
	memory[memIdx].l = nullptr;
	memory[memIdx].r = nullptr;
	return &memory[memIdx++];
}

void dfs(Tree* now) {
	if (now) {
		dfs(now->l);
		cout << now->ch;
		dfs(now->r);
	}
}

int main() {
	for (int t = 1; t <= 10; ++t) {
		cin >> total;
		for (int i = 0; i < total; ++i) {
			int idx;
			char ch;
			int a, b;

			cin >> idx;

			if (total % 2 == 0) {
				if (idx < total / 2) {
					cin >> ch >> a >> b;
					Tree* node = create(idx, ch);
					node->l = &memory[a - 1];
					node->r = &memory[b - 1];
				} else if (idx == total / 2) {
					cin >> ch >> a;
					Tree* node = create(idx, ch);
					node->l = &memory[a - 1];
				} else {
					cin >> ch;
					create(idx, ch);
				}
			} else {
				if (idx <= total / 2) {
					cin >> ch >> a >> b;
					Tree* node = create(idx, ch);
					node->l = &memory[a - 1];
					node->r = &memory[b - 1];
				} else {
					cin >> ch;
					create(idx, ch);
				}
			}
		}
		cout << "#" << t << " ";
		dfs(&memory[0]);
		cout << '\n';
		memIdx = 0;
	}
	return 0;
}
