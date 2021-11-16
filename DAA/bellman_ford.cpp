#include <iostream>
#include <climits>
#include <vector>
using namespace std;
 
class Edge {
public:
  int u, v, w;
};
 
class Graph {
public:
  int vertices;
  int edges;
  vector<Edge*> edge;
};
 
void display(vector<int> arr) {
  for(int i = 0; i <arr.size(); i++) {
      cout << arr[i] << " ";
  }
 
  cout << endl;
}
 
void bellmanford(Graph *g, int source) {
  int i, j, u, v, w;
 
  int noOfVertices = g->vertices;
  int noOfEdges = g->edges;
 
  vector<int> distance(noOfVertices, INT_MAX);
  vector<int> parent(noOfVertices, 0);
 
 
  distance[source] = 0;
  for(i = 1; i <= noOfVertices; i++) {
      for(j = 0; j < noOfEdges; j++) {
          u = g->edge[j]->u;
          v = g->edge[j]->v;
          w = g->edge[j]->w;
 
          // relaxation
          if(distance[u] != INT_MAX && distance[v] > distance[u] + w) {
              distance[v] = distance[u] + w;
              parent[v] = u;
          }
 
      }
  }
 
  for(j = 0; j < noOfEdges; j++) {
      u = g->edge[j]->u;
      v = g->edge[j]->v;
      w = g->edge[j]->w;
 
      // relaxation
      if(distance[u] != INT_MAX && distance[v] > distance[u] + w) {
          cout << "\nNegativie cycle exists!" << endl;
          return;
      }
  }
 
  cout << "Distance array: ";
  display(distance);
 
  cout << "Predecessor array: ";
  display(parent);
}
 
int main() 
{
    // create Graph
    Graph *g = new Graph();
 
    cout << "Enter no of vertices/nodes: ";
    cin >> g->vertices;
 
    cout << "Enter no of edges: ";
    cin >> g->edges;
 
    cout << "Enter edges (from to weight): " << endl;
    g->edge.resize(g->edges);
 
    for(int i = 0; i < g->edges; i++) {
        g->edge[i] = new Edge();
        cin >> g->edge[i]->u;
        cin >> g->edge[i]->v;
        cin >> g->edge[i]->w;
    }
 
    bellmanford(g, 0);
 
    return 0;
}

/*
 * Sample Output:

Enter no of vertices/nodes: 7
Enter no of edges: 10
Enter edges (from to weight): 
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
3 2 -2
2 4 1
3 5 -1
4 6 3
5 6 3
Distance array: 0 1 3 5 0 4 3 
Predecessor array: 0 2 3 0 1 3 4 
 
 * 
 * */
