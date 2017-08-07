#include <iostream>
#include <list>

using namespace std;

class BfsGraph{

    public:
    BfsGraph(int numVertices);
    void BfsIteration(int startVertice);
    void AddEdge(int vertice, int connectedVertice);

    private:
    bool *v;
    list<int> *adjacent;
};


BfsGraph::BfsGraph(int numVertice)
{

    v = new bool[numVertice];
    adjacent = new list<int>[numVertice];
}

void BfsGraph::AddEdge(int vertice, int connectedVertice)
{
   adjacent[vertice].push_back(connectedVertice);
   cout << "vertice " << vertice << " connected to " << connectedVertice << endl;
}

void BfsGraph::BfsIteration(int startVertice)
{
   v[startVertice] = true;
   list<int>::iterator it;
   list<int> queue;
   int value;
   queue.push_back(startVertice);

   while (!queue.empty())
   {
        value = queue.front();
        queue.pop_front();
        cout << value << " ";
        for (it = adjacent[value].begin(); it != adjacent[value].end(); it++)
        {
            if (v[*it] != true)
            {
                v[*it] = true;
                queue.push_back(*it);
            }
        } 

   }
}

int main()
{
    BfsGraph bg(4);
    bg.AddEdge(0, 1);
    bg.AddEdge(0, 2);
    bg.AddEdge(1, 2);
    bg.AddEdge(2, 0);
    bg.AddEdge(2, 3);
    bg.AddEdge(3, 3);

   cout << "Depth first traversal for following graph is: ";
   bg.BfsIteration(2);
   cout << endl;
}

