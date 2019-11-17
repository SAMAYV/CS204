#include<iostream> 
#include<list> 
using namespace std; 

class Graph 
{ 
    int V;    
    list<int> *adj; 
    void DFSUtil(int v, bool visited[]); 
	public: 
    Graph(int V);   
    void addEdge(int v, int w); 
    void DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true; 
    cout << v << " "; 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 

void Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
    DFSUtil(v, visited); 
} 
  
int main() 
{ 
    int V,E;
    cout<<"Enter number of vertices and edges"<<endl;
    cin>>V>>E;
    Graph* g = new Graph(4);
    for(int i=0;i<E;i++)
    {
        int e1,e2;
        cout<<"Enter both vertices of"<<"ith edge"<<endl;
        cin>>e1>>e2;
        g->addEdge(e1,e2);  
    } 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g->DFS(2); 
    
    return 0;  
} 