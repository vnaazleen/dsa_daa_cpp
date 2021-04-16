/** 
 * @author: Vaseem Naazleen Shaik
 * Depth first search Algorithm
*/

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

    void dfs_helper(T src, map<T, bool> &visited)
    {
        /** recursive function that will traverse the graph*/

        cout << src << " ";
        visited[src] = true;
        for (T nbr : l[src])
        {
            if (!visited[nbr])
            {
                dfs_helper(nbr, visited);
            }
        }
    }

    void dfs(T src)
    {
        cout << "DFS: ";
        map<T, bool> visited;

        for (auto node : l)
        {
            visited[node.first] = false;
        }
        // call the recr function
        dfs_helper(src, visited);
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
    g.dfs(0);
}