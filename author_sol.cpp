#include <bits/stdc++.h>

using namespace std;

const int MAX = (int) 1e4;
vector<int> parent(MAX + 1);

int Find(int v) {
	// traverse the tree structure to find the absolute root (parent) of 'v'
	// apply 'Path Compression' to minimize the tree structure (as well as time complexity)
	if (parent[v] == v) {
		return v;
	}
	return parent[v] = Find(parent[v]);
}

void Union(int from, int to) {
	// change the absolute root (parent) of 'from' to the absolute root (parent) of 'x'
	if (parent[to] == to) {
		parent[from] = to;
	} else {
		Union(from, parent[to]);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<int> score(n);
		for (int i = 0; i < n; i++) {
			cin >> score[i];
		}
		// set the parent of every element to itself (initial)
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		int q;
		cin >> q;
		for (int i = 0; i < q; i++) {
			int type, x, y;
			cin >> type >> x;
			if (type == 0) {
				// find the absolute root (parent) of 'x' and 'y', then check if it's the same
				// if not, then there wil be two (2) cases:
				// case 1 - if the score of the absolute root (parent) of 'x' is less than the
				// score of the absolute root (parent) of 'y', then change the absolute root (parent)
				// of 'x' to the absolute root (parent) of 'y'
				// case 2 - if the score of the absolute root (parent) of 'x' is greater than the
				// score of the absolute root (parent) of 'y', then change the absolute root (parent)
				// of 'y' tot he absolute root (parent) of 'x'
				cin >> y;
				x = Find(x);
				y = Find(y);
				if (x == y) {
					cout << "Invalid query!" << '\n';
					continue;
				}
				if (score[x - 1] < score[y - 1]) {
					Union(x, y);
				} else if (score[x - 1] > score[y - 1]) {
					Union(y, x);
				}
			} else {
				// output the absolute root (parent) of 'x'
				cout << Find(x) << '\n';
			}
		}
	}
	return 0;
}
