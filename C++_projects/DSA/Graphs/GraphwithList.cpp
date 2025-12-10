#include <iostream>
using namespace std;
template <typename T>
class Node
{
    public:
    T vertex;
    Node<T> *next;


    Node(T v)
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
    int *vertices;

public:
    Graph(int V)
    {
        this->V = V;
        vertices = new int[V];
        adjList = new Node<T> *[V];
        for (int i = 0; i < V; i++)
        {
            adjList[i] = nullptr;
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
        {
            cout << vertices[i] << " ";
        }
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

};
int main()
{
    Graph<int> g(5);
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.display();

    return 0;
}