#include <iostream>
#include <map>
#include <list>
#include <queue>

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
        map<T, int> visited;
        queue<T> q;

        q.push(src);
        visited[src] = true;

        cout << "BFS: ";

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            cout << node << " ";

            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }

        cout << endl;
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