#include <iostream>
#include <vector>
#include <climits>
#include <string>

#define SIZE 10

using namespace std;

struct Graph {
    int adjMatrix[SIZE][SIZE] = {0};
    string vertexData[SIZE];

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight; // Undirected
    }

    void addVertexData(int vertex, const string& data) {
        vertexData[vertex] = data;
    }
};

void simulateSend(const string& from, const string& to, const string& message) {
    cout << "Sending from " << from << " to " << to << ": \"" << message << "\"" << endl;
}

int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < SIZE; ++v) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(Graph& g, int src, int target) {
    vector<int> dist(SIZE, INT_MAX);
    vector<int> parent(SIZE, -1);
    vector<bool> sptSet(SIZE, false);

    dist[src] = 0;

    for (int count = 0; count < SIZE - 1; ++count) {
        int u = minDistance(dist, sptSet);
        if (u == -1 || u == target) break;
        sptSet[u] = true;

        for (int v = 0; v < SIZE; ++v) {
            if (!sptSet[v] && g.adjMatrix[u][v] &&
                dist[u] + g.adjMatrix[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + g.adjMatrix[u][v];
            }
        }
    }

    // Build the path
    vector<int> path;
    for (int crawl = target; crawl != -1; crawl = parent[crawl]) {
        path.push_back(crawl);
    }

    // Output the path
    cout << "\nRouting path: ";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << g.vertexData[path[i]];
        if (i != 0) cout << " -> ";
    }
    cout << ", Distance: " << dist[target] << "\n\n";

    // Simulate sending the message
    const string message = "Hello";
    for (int i = path.size() - 1; i > 0; --i) {
        simulateSend(g.vertexData[path[i]], g.vertexData[path[i - 1]], message);
    }
}

int main() {
    Graph g;

    g.addVertexData(0, "A");
    g.addVertexData(1, "B");
    g.addVertexData(2, "C");
    g.addVertexData(3, "D");
    g.addVertexData(4, "E");
    g.addVertexData(5, "F");
    g.addVertexData(6, "G");
    g.addVertexData(7, "H");
    g.addVertexData(8, "I");
    g.addVertexData(9, "J");

    // Topology (undirected)
    g.addEdge(3, 0, 4);  // D - A
    g.addEdge(3, 4, 2);  // D - E
    g.addEdge(0, 2, 3);  // A - C
    g.addEdge(0, 4, 4);  // A - E
    g.addEdge(4, 2, 4);  // E - C
    g.addEdge(4, 6, 5);  // E - G
    g.addEdge(2, 5, 5);  // C - F
    g.addEdge(2, 1, 2);  // C - B
    g.addEdge(1, 5, 2);  // B - F
    g.addEdge(6, 5, 5);  // G - F
    g.addEdge(6, 8, 4);  // G - I
    g.addEdge(6, 7, 5);  // G - H
    g.addEdge(8, 9, 2);  // I - J

    cout << "Dijkstra's Routing Simulation: D -> F\n";
    dijkstra(g, 9, 5);  // From D to F

    return 0;
}
