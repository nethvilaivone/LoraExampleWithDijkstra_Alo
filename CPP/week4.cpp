#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define SIZE 10

typedef struct Graph {
    int adjMatrix[SIZE][SIZE];
    char* vertexData[SIZE];
} Graph;

void addEdge(Graph* g, int u, int v, int weight) {
    g->adjMatrix[u][v] = weight;
    g->adjMatrix[v][u] = weight; // Undirected graph
}

void addVertexData(Graph* g, int vertex, char* data) {
    g->vertexData[vertex] = data;
}

// Simulates sending a message from one node to another
void simulateSend(Graph* g, int from, int to, const char* message) {
    printf("Sending from %s to %s: \"%s\"\n", g->vertexData[from], g->vertexData[to], message);
}

// Returns the vertex with the minimum distance value not yet in sptSet
int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < SIZE; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Dijkstra's algorithm + routing simulation
void dijkstra(Graph* g, int src, int target) {
    int dist[SIZE];
    int sptSet[SIZE] = {0};
    int parent[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        parent[i] = -1;
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    for (int count = 0; count < SIZE - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u == -1 || u == target) break;

        sptSet[u] = 1;

        for (int v = 0; v < SIZE; v++) {
            if (!sptSet[v] && g->adjMatrix[u][v] &&
                dist[u] + g->adjMatrix[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + g->adjMatrix[u][v];
            }
        }
    }

    // Build the path in reverse
    int path[SIZE];
    int pathIndex = 0;
    for (int crawl = target; crawl != -1; crawl = parent[crawl]) {
        path[pathIndex++] = crawl;
    }

    // Print route
    printf("Routing path: ");
    for (int i = pathIndex - 1; i >= 0; i--) {
        printf("%s", g->vertexData[path[i]]);
        if (i != 0) printf(" -> ");
    }
    printf(", Distance: %d\n\n", dist[target]);

    // Simulate message delivery
    const char* message = "Hello";
    for (int i = pathIndex - 1; i > 0; i--) {
        simulateSend(g, path[i], path[i - 1], message);
    }
}
int main() {
    Graph g = {0};

    addVertexData(&g, 0, "A");
    addVertexData(&g, 1, "B");
    addVertexData(&g, 2, "C");
    addVertexData(&g, 3, "D");
    addVertexData(&g, 4, "E");
    addVertexData(&g, 5, "F");
    addVertexData(&g, 6, "G");
    addVertexData(&g, 7, "H");
    addVertexData(&g, 8, "I");
    addVertexData(&g, 9, "J");

    // Example topology
    addEdge(&g, 3, 0, 4);  // D - A
    addEdge(&g, 3, 4, 2);  // D - E
    addEdge(&g, 0, 2, 3);  // A - C
    addEdge(&g, 0, 4, 4);  // A - E
    addEdge(&g, 4, 2, 4);  // E - C
    addEdge(&g, 4, 6, 5);  // E - G
    addEdge(&g, 2, 5, 5);  // C - F
    addEdge(&g, 2, 1, 2);  // C - B
    addEdge(&g, 1, 5, 2);  // B - F
    addEdge(&g, 6, 5, 5);  // G - F
    addEdge(&g, 6, 8, 4);  // G - I
    addEdge(&g, 6, 7, 5);  // G - H
    addEdge(&g, 8, 9, 2);  // I - J

    printf("Dijkstra's Routing Simulation: D -> F\n\n");
    dijkstra(&g, 3, 5);  // From D to F

    return 0;
}
