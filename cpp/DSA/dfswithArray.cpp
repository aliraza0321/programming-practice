#include <iostream>
#include <stack>
#include <vector>
using namespace std;
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
    void dfsVisit(int s, vector<bool> &visited, stack<int> &q)
    {
        visited[s] = true;
        q.push(s);
        while (!q.empty())
        {
            int curr = q.top();
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

        void dfs()
        {
            cout << "DFS Traversal:" << endl;
            vector<bool> visited(V, false);
            stack<int> q;
            for (int i = 0; i < V; i++)
            {
                if (!visited[i])
                {
                    dfsVisit(i, visited, q);  // Call dFS for each component
                }
            }
        }
        bool cycleExit(int u, bool a[],int root)
        {
            a[u]=true;
            for(int i=0;i<V;i++)
            {
                if(Edges[u][i]==1&&a[i]!=true)
                {
                   if(cycleExit(i,a,u))
                   {
                    return true;
                   }
                }
                else{
                    if(u!=root)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool cycle()
        {
            bool *arr=new bool[5];
            for(int i=0;i<5;i++)
            {
                arr[i]=false;
            }
            for(int u=0;u<5;u++)
            {
                if(!arr[u])
                {
                    if(cycleExit(u,arr,-1))
                    {
                        return true;
                    }
                }
            }
            return false;
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
        //g.addEdge(0, 2);
        g.addEdge(3, 4);
       // g.addEdge(2, 4);
        g.display();
        if(g.cycle())
        {
         cout<<"\nYes\n";
        }
        else{
            cout<<"\nNo\n";
        }
        g.dfs();
    }