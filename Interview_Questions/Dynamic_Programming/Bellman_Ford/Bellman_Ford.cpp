/*
 * Bellman–Ford algorithm computes shortest paths from a single source vertex to all of the other vertices in a weighted graph.
 * Advantage over Dijkstra's algorithm is that it can detect negative cycles in a graph.
 * Application : Used in RIP, Babel routing protocol
 * Time Complexiy : O(VxE) for one source and O(V^2 X E) for all vertices as source
 * Space Complexity : O(V)

 */
/* Header Files
 */
#include <iostream>
#include <stdio.h>

using namespace std;

/* Global variable
 */
#define INVALID 65535


/* Structure Proto-type
 */
typedef struct EDGE
{
	unsigned int src;
        unsigned int dest;
        int weight;
}Edge;

typedef struct GRAPH
{
	unsigned int V;
        unsigned int E;

	Edge* edge;
}Graph;


/* Function Proto-type
 */
Graph* createGraph(unsigned int V, unsigned int E);
void printVertextDistance(int dist[], int n);
void BellmanFord(Graph* graph, int src);


int main()
{
	unsigned int E = 6;
        unsigned int V = 5;
	Graph* graph = createGraph(V, E);

	graph->edge[0].src    = 1;
	graph->edge[0].dest   = 1;
	graph->edge[0].weight = -2;

	graph->edge[1].src    = 0;
	graph->edge[1].dest   = 2;
	graph->edge[1].weight = 8;

	graph->edge[2].src    = 3;
	graph->edge[2].dest   = 2;
	graph->edge[2].weight = 2;

	graph->edge[3].src    = 2;
	graph->edge[3].dest   = 3;
	graph->edge[3].weight = 2;

	graph->edge[4].src    = 1;
	graph->edge[4].dest   = 4;
	graph->edge[4].weight = 3;

	graph->edge[5].src    = 3;
	graph->edge[5].dest   = 1;
	graph->edge[5].weight = 4;

	graph->edge[6].src    = 3;
	graph->edge[6].dest   = 1;
	graph->edge[6].weight = 2;

	BellmanFord(graph, 0);

	return 0;
}


void BellmanFord(Graph* graph, int src)
{
	unsigned int V = graph->V;
	unsigned int E = graph->E;
	int dist[V];

        // Initialize all distances from source to other vertices invalid
        for (int index = 0; index < V; index++)
        {
            if (index != src)
            {
                dist[index] = INVALID;
            }
            else
            {
                dist[index] = 0;
            }
        }

	// Relaxation of vertices
	for (int indexout = 1; indexout <= V-1; indexout++)
	{
		for (int indexin = 0; indexin < E; indexin++)
		{
			unsigned int u = graph->edge[indexin].src;
			unsigned int v = graph->edge[indexin].dest;
			int weight = graph->edge[indexin].weight;
			
                        // If parent is has no route it cannot find a route for child
                        if (dist[u] == INVALID)
                        {
                            continue;
                        }
                        // If child distance is greater than parent distance + weight of edge 
                        // then update child distance with parent distance + weight of edge
                        else if(dist[v] > dist[u] + weight)
                        {
				dist[v] = dist[u] + weight;
                        }
		}
	}

	printVertextDistance(dist, V);

	for (int index = 0; index < E; index++)
	{
		unsigned int u = graph->edge[index].src;
		unsigned int v = graph->edge[index].dest;
		int weight = graph->edge[index].weight;

                // If parent is has no route it cannot find a route for child
                if (dist[u] == INVALID)
                {
                     continue;
                }
                
                // If child distance is greater than parent distance + weight of edge 
                // then update child distance with parent distance + weight of edge
                else if(dist[v] > dist[u] + weight)
                {
		    cout << "This graph has negative weight cycle";
                }			
	}
	return;
}


Graph* createGraph(unsigned int V, unsigned int E)
{
	Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;
	graph->edge = new Edge[E];
	return graph;
}


void printVertextDistance(int dist[], int n)
{
    cout << "Vertex \t | Distance from Source\n";
    for (int index = 0; index < n; ++index)
    {
	printf("%d \t | %d\n", index, dist[index]);
    }
}

