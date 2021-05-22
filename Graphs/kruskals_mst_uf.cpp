#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> size;

int find_root(int x) {
	if (parent[x] == x) {
		return x;
	} 
	return parent[x] = find_root(parent[x]); // path_compression
}

bool merge(int x, int y) {
	x = find_root(x);
	y = find_root(y);

	if(x == y) return false;

	if(size[x] > size[y]) {
		swap(x, y);
	}
	parent[x] = y;
	size[y] += size[x];
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;

	parent.resize(n);
	for(int i = 0; i < n; i++)
		parent[i] = i;
	size.resize(n, 1);

	// input graph
	vector<pair<int, pair<int, int>>> edges(m);
	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edges[i] = {w, {u-1, v-1}};
	}

	// sort the edges
	sort(edges.begin(), edges.end());

	int ans = 0;
	for(auto p : edges) {
		// if both are nodes are in different component, merge returns true and we add edge cost
		if(merge(p.second.first, p.second.second)) {
			ans += p.first;
		}
	}

	cout << ans << endl;
	return 0;
}
