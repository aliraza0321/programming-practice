#include<iostream>
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
        this->V=V;
        vertices=new T[V];
        Edges=new int*[V];
        for(int i=0;i<V;i++)
        {
            Edges[i]=new int[V];
        }
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                Edges[i][j]=0;
            }
        }
        start=-1;
    }
    void addVertex(T v)
    {
        start++;
        if(start<V)
        {
            vertices[start]=v;
        }
        else
        {
            cout<<"Vertex limit exceeded"<<endl;
        }

    }
    void addEdge(int v1,int v2)
    {
        Edges[v1][v2]=1;
        Edges[v2][v1]=1;

    }
    void display()
    {
        cout<<"Vertices:"<<endl;
        for(int i=0;i<V;i++)
        {
            cout<<vertices[i]<<" ";
        }
        cout<<endl;
        cout<<"Adjacency Matrix:"<<endl;
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cout<<Edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main()
{
    Graph<string> g(3);
    g.addVertex("A");
    g.addVertex("B");
    g.addVertex("C");
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);
    g.display();
    
}