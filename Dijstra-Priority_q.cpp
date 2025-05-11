#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <string>

#define SIZE 10

using namespace std;

class Graph {
    public:
    int adjMatrix[SIZE][SIZE] = {0};
    string vertexData[SIZE];

    Graph() {
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                adjMatrix[i][j] = 0;
            }
        }
    }
    void addEdge(int u, int v, int weight) {
        
        int absWeight = abs(weight);
        if (absWeight > 0) {
            adjMatrix[u][v] = absWeight;
            adjMatrix[v][u] = absWeight; // Undirected graph
        }
        else {
            adjMatrix[u][v] = 0;
            adjMatrix[v][u] = 0; // No edge
        }
    }

    void addVertexData(int vertex, const string& data) {
        vertexData[vertex] = data;
    }
};

void simulateSend(const string& from, const string& to, const string& message) {
    cout << "Sending from " << from << " to " << to << ": \"" << message << "\"" << endl;
}


void dijkstra(Graph& g, int src, int target) {
    vector<int> dist(SIZE, INT_MAX);
    vector<int> parent(SIZE, -1);
    vector<bool> visited(SIZE, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        if (u == target) break;

        for (int v = 0; v < SIZE; ++v) {
            if (g.adjMatrix[u][v] > 0 && !visited[v]) {
                int alt = dist[u] + g.adjMatrix[u][v];
                if (alt < dist[v]) {
                    dist[v] = alt;
                    parent[v] = u;
                    pq.push({alt, v});
                }
            }
        }
    }

    vector<int> path;
    for (int crawl = target; crawl != -1; crawl = parent[crawl])
        path.push_back(crawl);

    cout << "\nRouting path: ";
    for (int i = path.size() - 1; i >= 0; --i) {
        cout << g.vertexData[path[i]];
        if (i != 0) cout << " -> ";
    }
    cout << ", Distance: " << dist[target] << "\n\n";

    string message = "Hello";
    for (int i = path.size() - 1; i > 0; --i) {
        simulateSend(g.vertexData[path[i]], g.vertexData[path[i - 1]], message);
    }
}

int main() {
    Graph g = Graph();
    Graph();
    
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

    g.addEdge(3, 0, -4);  // D - A
    g.addEdge(3, 4, -2);  // D - E
    g.addEdge(0, 2, -3);  // A - C
    g.addEdge(0, 4, -4);  // A - E
    g.addEdge(4, 2, -4);  // E - C
    g.addEdge(4, 6, -5);  // E - G
    g.addEdge(2, 5, -5);  // C - F
    g.addEdge(2, 1, -2);  // C - B
    g.addEdge(1, 5, -2);  // B - F
    g.addEdge(6, 5, -5);  // G - F
    g.addEdge(6, 8, -4);  // G - I
    g.addEdge(6, 7, -5);  // G - H
    g.addEdge(8, 9, -2);  // I - J

    cout << "Dijkstra's Routing Simulation: D -> F\n";
    dijkstra(g, 9, 5);  // From D to F

    return 0;
}
