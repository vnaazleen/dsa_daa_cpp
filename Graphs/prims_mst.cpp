#include <bits/stdc++.h>
using namespace std;


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);

	for(int i = 0; i < m; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		g[a-1].push_back({b-1, w});
		g[b-1].push_back({a-1, w});	
	}

	priority_queue< pair<int, pair<int, int> >, vector< pair<int, pair<int, int> > >, greater< pair<int, pair<int, int> > > > pq;

	for(auto i : g[0]) {
		int u = i.first, wt = i.second;
		pq.push({wt, {0, u}});
	}

	vector<int> visited(n);
	visited[0] = 1;

	int total_cost = 0;
	while(!pq.empty()) {
		auto cur = pq.top();
		pq.pop();

		int u = cur.second.second;
		int w = cur.first;

		if(visited[u])
			continue;

		total_cost += w;
		visited[u] = 1;
		for(auto i : g[u]) {
			int v = i.first, nw = i.second;
			if(!visited[v])
				pq.push({nw, {u, v}});
		}
	}

	cout << total_cost << endl;
	return 0;
}