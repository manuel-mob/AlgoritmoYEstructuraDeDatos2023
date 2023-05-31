#include <iostream>
#include <limits>
#include <vector>

#define INF std::numeric_limits<int>::max()

// Function to find the vertex with the minimum distance value
int findMinDistance(const std::vector<int>& distances, const std::vector<bool>& visited, int V) {
    int minDistance = INF;
    int minIndex = -1;

    for (int v = 0; v < V; ++v) {
        if (!visited[v] && distances[v] < minDistance) {
            minDistance = distances[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to print the shortest path from the source to each vertex
void printShortestPaths(const std::vector<int>& distances, int V, int source) {
    std::cout << "Shortest paths from vertex " << source << ":\n";
    for (int v = 0; v < V; ++v) {
        std::cout << "Vertex " << v << ": ";
        if (distances[v] == INF)
            std::cout << "No path";
        else
            std::cout << distances[v];
        std::cout << '\n';
    }
}

// Function to implement Dijkstra's algorithm
void dijkstraAlgorithm(const std::vector<std::vector<int>>& graph, int V, int source) {
    std::vector<int> distances(V, INF);  // Distance from source to each vertex
    std::vector<bool> visited(V, false); // Visited array to track visited vertices

    // Distance from source to itself is always 0
    distances[source] = 0;

    for (int count = 0; count < V - 1; ++count) {
        int u = findMinDistance(distances, visited, V);
        visited[u] = true;

        // Update the distances of neighboring vertices
        for (int v = 0; v < V; ++v) {
            if (!visited[v] && graph[u][v] && distances[u] != INF && distances[u] + graph[u][v] < distances[v])
                distances[v] = distances[u] + graph[u][v];
        }
    }

    // Print the shortest paths
    printShortestPaths(distances, V, source);
}

int main() {
    int V; // Number of vertices
    int source; // Source vertex
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;
    std::cout << "Enter the source vertex: ";
    std::cin >> source;

    std::vector<std::vector<int>> graph(V, std::vector<int>(V));

    std::cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cin >> graph[i][j];
        }
    }

    dijkstraAlgorithm(graph, V, source);

    std::cout << "Adjacency Matrix:" << std::endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
                std::cout << graph[i][j] << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
