#include <iostream>
using namespace std;
#include <queue>
#include <vector>
template <typename T>
class Graph
{
    int V;
    int start;
    T *vertices;
    int **Edges;

public:
    Graph(int V)
    {
        this->V = V;
        vertices = new T[V];
        Edges = new int *[V];
        for (int i = 0; i < V; i++)
        {
            Edges[i] = new int[V];
        }
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                Edges[i][j] = 0;
            }
        }
        start = -1;
    }
    void addVertex(T v)
    {
        start++;
        if (start < V)
        {
            vertices[start] = v;
        }
        else
        {
            cout << "Vertex limit exceeded" << endl;
        }
    }
    void addEdge(int v1, int v2)
    {
        Edges[v1][v2] = 1;
        Edges[v2][v1] = 1;
    }
    void display()
    {
        cout << "Vertices:" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << vertices[i] << " ";
        }
        cout << endl;
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << Edges[i][j] << " ";
            }
            cout << endl;
        }
    }
    void bfsVisit(int s, vector<bool> &visited, queue<int> &q)
    {
        visited[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            cout << vertices[curr] << " ";
            for (int i = 0; i < V; i++)
            {
                if (Edges[curr][i] == 1 && !visited[i])
                {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

        void bfs()
        {
            cout << "BFS Traversal:" << endl;
            vector<bool> visited(V, false);
            queue<int> q;
            for (int i = 0; i < V; i++)
            {
                if (!visited[i])
                {
                    bfsVisit(i, visited, q);  // Call BFS for each component
                }
            }
        }
    };
    int main()
    {
        Graph<string> g(5);
        g.addVertex("A");
        g.addVertex("B");
        g.addVertex("C");
        g.addVertex("D");
        g.addVertex("E");
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(0, 2);
        g.addEdge(3, 4);
       // g.addEdge(2, 4);
        g.display();
        g.bfs();
    }