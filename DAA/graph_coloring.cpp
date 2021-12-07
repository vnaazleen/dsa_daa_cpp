#include <iostream>
#include <vector>


using namespace std;

int m; // no of colors
int n; // no of vertices or nodes in the graph

int c = 0;
int sol = 0; // no of solutions

vector<int> x; // Solution vector
vector<vector<int>> g; // graph

void next_value(int k) {
	int j;
	while(1) {
		x[k] = (x[k] + 1) % (m + 1);
		if(x[k] == 0) {
			return;
		} 
		
		for(j = 1; j <= n; j++) {
			if(g[k][j] == 1 && x[k] == x[j]) {
				break;
			}
		}
		
		if(j == (n + 1)) {
			return;
		}
	}
}

void graph_coloring(int k) {
	while(1) {
		next_value(k);
		if(x[k] == 0) {
			return;
		}
		
		if(k == n) {
			c = 1;
			for(int i = 1; i <= n; i++) {
				cout << x[i] << " ";
			}
			sol++;
			cout << endl;
		} else {
			graph_coloring(k+1);
		}
	}
}

int main() {
	
	cout << "Enter no of vertices in the graph: ";
	cin >> n;
	
	cout << "Enter graph edges in form of adj list" << endl;
	g.resize(n+1, vector<int>(n+1, 0)); // graph
	x.resize(n + 1);
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	
	cout << "All possible solutions are:\n";
	for(m = 1; m <= n; m++) {
		if(c == 1) {
			break;
		}
		
		graph_coloring(1);
	}
	
	cout << "\nChromatic number is: " << (m-1) << endl;
	cout << "Total no of solutions: " << sol << endl; 	
	
}
