#include <iostream>

using namespace std;

class Edge {
    public:
        int source, destination, weight; 
};

class Graph {
    public:
        int numberofvertices, numberofedges;

        Edge *edge;
};

Graph *createGraph(int vertices, int edges) {
    Graph *graph = new Graph();
    graph->numberofvertices = vertices;
    graph->numberofedges = edges;

    graph->edge = new Edge[edges];

    return graph;
}

void BellmanFord(Graph *graph, int src) {
    int V = graph->numberofvertices;
    int E = graph->numberofedges;
    int dist[V];

    for(int i=0; i<V; i++) {
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for(int i=1; i<= V-1; i++) {
        for(int j=0; j<E; j++) {
            int u = graph->edge[j].source;
            int v = graph->edge[j].destination;
            int weight = graph->edge[j].weight;
            if(dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for(int i=0; i<E; i++) {
        int u = graph->edge[i].source;
        int v = graph->edge[i].destination;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
        }
    }


    cout << "Vertex    Distance from source" << endl;

    for(int i=0; i<V; ++i) {
        cout << i << "    " << dist[i] << endl;
    }

    return;
}

int main() {
    int V = 4;
    int E = 5;

    Graph *graph = createGraph(V, E);

    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 10;

    graph->edge[1].source = 0;
    graph->edge[1].destination = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].source = 0;
    graph->edge[2].destination = 3;
    graph->edge[2].weight = 5;

    graph->edge[3].source = 1;
    graph->edge[3].destination = 3;
    graph->edge[3].weight = 15;

    graph->edge[4].source = 2;
    graph->edge[4].destination = 3;
    graph->edge[4].weight = 4;

    BellmanFord(graph, 0);

    return(0);
}
