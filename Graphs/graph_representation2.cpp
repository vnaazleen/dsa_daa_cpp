/** 
 * @author: Vaseem Naazleen Shaik
 * Graph -> directed & undirected, weighted graph repreentation using Adjacency list
*/

#include <iostream>
#include <unordered_map>
#include <list>
#include <cstring>

using namespace std;

class Graph
{
private:
    unordered_map<string, list<pair<string, int>>> g;

public:
    void addEdge(string x, string y, bool bidirectional, int wt)
    {
        g[x].push_back(make_pair(y, wt));
        if (bidirectional)
        {
            g[y].push_back(make_pair(x, wt));
        }
    }

    void print()
    {
        for (auto node_pair : g)
        {
            string node = node_pair.first;
            list<pair<string, int>> neighbours = node_pair.second;

            for (auto nbr : neighbours)
            {
                string dest = nbr.first;
                int dist = nbr.second;

                cout << dest << " " << dist << " , ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);
    g.print();
}