/** 
 * @author: Vaseem Naazleen Shaik
 * Single source shortest path using Breadth first search Algorithm (SSSP using BFS)
*/

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>

using namespace std;

template <typename T>
class Graph
{
private:
    map<T, list<T>> l;

public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(T src)
    {
        map<T, int> distance;
        queue<T> q;

        // initially all nodes will have infinte dist from source (assumption)
        for (auto node : l)
        {
            distance[node.first] = INT_MAX;
        }

        q.push(src);
        distance[src] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            for (auto nbr : l[node])
            {
                if (distance[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    distance[nbr] = distance[node] + 1;
                }
            }
        }

        cout << "node"
             << " dist" << endl;
        for (auto node : l)
        {
            cout << node.first << "     " << distance[node.first] << endl;
        }
    }

    void print()
    {
        for (auto node : l)
        {
            cout << node.first << " -> ";
            for (T nbr : node.second)
            {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(0, 3);
    g.print();
    g.bfs(0);
}