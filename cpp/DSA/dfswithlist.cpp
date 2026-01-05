#include <iostream>
#include <stack>
#include<list>
#include <vector>
using namespace std;

template <typename T>
class Node
{
public:
    int vertex;
    Node<T> *next;

    Node(int v)
    {
        vertex = v;
        next = nullptr;
    }
};

template <typename T>
class Graph
{
    int V;
    int start;
    Node<T> **adjList;
    T *vertices; // FIXED: int → T

public:
    Graph(int V)
    {
        this->V = V;
        vertices = new T[V];
        adjList = new Node<T> *[V];

        for (int i = 0; i < V; i++)
            adjList[i] = nullptr;

        start = -1;
    }

    void addVertex(T v)
    {
        start++;
        if (start < V)
            vertices[start] = v;
        else
            cout << "Vertex limit exceeded" << endl;
    }

    void addEdge(int v1, int v2)
    {
        Node<T> *newNode1 = new Node<T>(v2);
        newNode1->next = adjList[v1];
        adjList[v1] = newNode1;

        Node<T> *newNode2 = new Node<T>(v1);
        newNode2->next = adjList[v2];
        adjList[v2] = newNode2;
    }

    void display()
    {
        cout << "Vertices:" << endl;
        for (int i = 0; i < V; i++)
            cout << vertices[i] << " ";
        cout << endl;

        cout << "Adjacency List:" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << vertices[i] << ": ";
            Node<T> *temp = adjList[i];
            while (temp != nullptr)
            {
                cout << vertices[temp->vertex] << " ";
                temp = temp->next;
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

            Node<T> *temp = adjList[curr];
            while (temp != nullptr)
            {
                int adjVertex = temp->vertex;

                if (!visited[adjVertex])
                {
                    visited[adjVertex] = true;
                    q.push(adjVertex);
                }
                temp = temp->next;
            }
        }
    }

    void dfs()
    {
        cout << "\nDFS Traversal: ";
        vector<bool> visited(V, false);
        stack<int> q;

        for (int i = 0; i < V; i++)
            if (!visited[i])
                dfsVisit(i, visited, q);
    }
    bool isCyclicUtil(int v, bool visited[], int parent)
    {
        visited[v] = true;
        list<int>::iterator i;
        for (i =adjList[v].begin(); i != adjList[v].end(); ++i)
        {
            if (!visited[*i])
            {
                if (isCyclicUtil(*i, visited, v))
                    return true;
            }
            else
            {
                if (*i != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCyclic()
    {

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        for (int u = 0; u < V; u++)
            if (!visited[u])
                if (isCyclicUtil(u, visited, -1))
                    return true;
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
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();
    g.dfs();
    if (g.isCyclic())
    {
        cout << "\nYes\n";
    }
    else
    {
        cout << "\nNo\n";
    }
    return 0;
}
