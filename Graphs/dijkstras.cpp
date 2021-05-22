#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

int dijkstra(vector<pair<int, int>> g[], int n, int src, int dest) {
	vector<int> dist(n, INT_MAX);
	set<pair<int, int>> s;

	dist[src] = 0;
	s.insert({0, src});

	while(!s.empty()) {
		auto it = s.begin();
		int cur = it->second;
		s.erase(it);

		for(auto nbr_pair : g[cur]) {

			int nbr = nbr_pair.first;
			int edge_dist = nbr_pair.second;

			if(dist[cur] + edge_dist < dist[nbr]) {
				auto f = s.find({dist[nbr], nbr});
				if(f != s.end()) {
					s.erase(f);
				}

				dist[nbr] = dist[cur] + edge_dist;
				s.insert({dist[nbr], nbr});
			}
		}
		
	} 

	return dist[dest];
}

int main() {
	int n, m; // n -> nodes, m -> edges
	cin >> n >> m;

	vector<pair<int, int>> g[n];
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	int src, dest;
	cin >> src >> dest;

	cout << dijkstra(g, n, src, dest) << endl;
}