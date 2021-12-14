#include <iostream>
#include <vector>

using namespace std;

int n, c = 0; // n => no of vertices, c = no of solutions
vector<vector<int>> g; // graph (adj matrix)
vector<int> x; // visited array

void display_cycle() {
	for(int i = 1; i <= n; i++) { cout << x[i] << " "; }
	cout << x[1] << endl;
}

void next_value(int k) {
	int j;
	while(1) {
		x[k] = (x[k] + 1) % (n + 1); // trying the next val
		
		// if soln is not possible, traceback
		if(x[k] == 0) {
			return;
		}
		
		// if there is an edge between prev node & this node
		if(g[x[k - 1]][x[k]]) {
			// check if this node is already visited or not
			for(j = 1; j <= k - 1; j++) {
				// if already visited, break 
				if(x[j] == x[k]) {
					break;
				}
			}
			
			// not visited, then
			if(j == k) {
				
				// if there are still vertexes to visit
				// or this is last vertex and has edge to source 
				// then solution is found, so return
				
				if((k < n) || (k == n && g[x[n]][x[1]] != 0)) {
					return;
				}
			}
		}
	}
}

void hamiltonian(int k) {
	while(1) {
		next_value(k);
		
		// if solution is not possible, trace back
		if(x[k] == 0) {
			return;
		} 
		
		// if solution is found, display it
		if(k == n) {
			c = c + 1;
			display_cycle();
		} else { 
			hamiltonian(k + 1);
		}
	}
}

int main() {
	
	int i, j;
	cout << "Enter no of vertices: ";
	cin >> n;
	
	g.resize(n + 1, vector<int>(n + 1, 0));
	x.resize(n + 1, 0);
	
	cout << "Enter the graph (adj matrix): " << endl;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	
	x[1] = 1; // mark start node 1 as visited
	cout << "\nHamiltonian cycles possible are: " << endl;
	
	hamiltonian(2);
	
	if(c == 0) {
		cout << "Solution not possible" << endl;
	} else {
		cout << "Total " << c << " solutions are found" << endl;
	}
	
	return 0;
}
