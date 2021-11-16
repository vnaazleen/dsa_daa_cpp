#include <iostream>
#include <vector>
#include <climits>
 
using namespace std;
 
void floyd_warshall(vector<vector<int>>& dist, int n) {
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(i == j) {
					dist[i][j] = 0;
				} else {
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}
			}
		}
	}
}
 
int main() {
	int vertices;
	cout << "Enter no of vertices: ";
	cin >> vertices;
 
	int edges;
	cout << "Enter no of edges: ";
	cin >> edges;
 
	vector<vector<int>> cost(vertices+1, vector<int>(vertices+1, 1000));
 
	int u, v, wt;
	cout << "Enter edges: " << endl;
	for(int edge = 0; edge < edges; edge++) {
		cout << "Enter edge (format: u v weight): ";
		cin >> u >> v >> wt;
		cost[u][v] = wt;
	}
 
	cout << "\n ----- COST MATRIX -----\n";
	for(int i = 1; i <= vertices; i++) {
		for(int j = 1; j <= vertices; j++) {
			if(cost[i][j] == 1000)
				cout << "inf" << " ";
			else
				cout << cost[i][j] << " ";
		}
		cout << endl;
	}
 
	floyd_warshall(cost, vertices);
 
	cout << "\n ----- SHORTEST PATH MATRIX -----\n";
	for(int i = 1; i <= vertices; i++) {
		for(int j = 1; j <= vertices; j++) {
			cout << cost[i][j] << " ";
		}
		cout << endl;
	}
 
	for(int i = 1; i <= vertices; i++) {
		for(int j = 1; j <= vertices; j++) {
			if(i != j) {
				cout << "Shortest path from " << i << " to " << j << " is " << cost[i][j] << endl;
			}
		}
	}
}

/*
Sample output: 
Enter no of vertices: 4
Enter no of edges: 6
Enter edges: 
Enter edge (format: u v weight): 1 2 3
Enter edge (format: u v weight): 2 1 2
Enter edge (format: u v weight): 1 4 5
Enter edge (format: u v weight): 2 4 4
Enter edge (format: u v weight): 3 2 1
Enter edge (format: u v weight): 4 3 2

 ----- COST MATRIX -----
inf 3 inf 5 
2 inf inf 4 
inf 1 inf inf 
inf inf 2 inf 

 ----- SHORTEST PATH MATRIX -----
0 3 7 5 
2 0 6 4 
3 1 0 5 
5 3 2 0 
Shortest path from 1 to 2 is 3
Shortest path from 1 to 3 is 7
Shortest path from 1 to 4 is 5
Shortest path from 2 to 1 is 2
Shortest path from 2 to 3 is 6
Shortest path from 2 to 4 is 4
Shortest path from 3 to 1 is 3
Shortest path from 3 to 2 is 1
Shortest path from 3 to 4 is 5
Shortest path from 4 to 1 is 5
Shortest path from 4 to 2 is 3
Shortest path from 4 to 3 is 2

*/
