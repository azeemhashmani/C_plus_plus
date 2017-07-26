#ifdef COMMENTS
- The depth first search algo is similar to depth first algo of a tree. Because of loops we would be visiting nodes many times hence we need to maintaion a bool of array to visit each node only once
Applications:
- We can check if there exist a path between two nodes using depth first search and using stack we can save the path
- Solving maze puzzle is an application of depth first search
- To check if a node is connected witht the graph
#endif 

#include <iostream>
#include <list>

using namespace std;

class DfsGraph{

    public:
    DfsGraph(int numVertices);
    void DfsIteration(int startVertice);
    void AddEdge(int vertice, int connectedVertice);
    private:
    bool *v;
    list<int> *adjacent; 
};


DfsGraph::DfsGraph(int numVertices)
{
      v = new bool[numVertices];
      adjacent = new list<int>[numVertices];
}   

void DfsGraph::DfsIteration(int startVertice)
{
     v[startVertice] = true;
     cout << startVertice << " ";  
     list <int>::iterator it;


     for (it = adjacent[startVertice].begin(); it != adjacent[startVertice].end(); it++)
     {    
         if (v[*it] != true)
         {  
              DfsIteration(*it);
         }
     } 
}

void DfsGraph::AddEdge(int vertice, int connectedVertice)
{
     adjacent[vertice].push_back(connectedVertice);
     cout << "vertice " << vertice << " connected to " << connectedVertice << endl;
}


int main()
{
    DfsGraph dg(4);
    dg.AddEdge(0, 1);
    dg.AddEdge(0, 2);
    dg.AddEdge(1, 2);
    dg.AddEdge(2, 0);
    dg.AddEdge(2, 3);
    dg.AddEdge(3, 3);

   cout << "Depth first traversal for following graph is: ";
   dg.DfsIteration(2);
   cout << endl;
}
