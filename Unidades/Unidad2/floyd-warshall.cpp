#include <iostream>
#include <limits>
#include <vector>

#define INF std::numeric_limits<int>::max()

// Function to print the shortest distances matrix
void printShortestDistances(const std::vector<std::vector<int>>& distances, int V) {
    std::cout << "Shortest distances between vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (distances[i][j] == INF)
                std::cout << "INF ";
            else
                std::cout << distances[i][j] << " ";
        }
        std::cout << '\n';
    }
}

// Function to implement Floyd-Warshall algorithm
void floydWarshallAlgorithm(const std::vector<std::vector<int>>& graph, int V) {
    std::vector<std::vector<int>> distances(graph); // Initialize the distance matrix with the given graph

    // Applying the Floyd-Warshall algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from vertex i to j, update the distance
                if (distances[i][k] != INF && distances[k][j] != INF && distances[i][k] + distances[k][j] < distances[i][j])
                    distances[i][j] = distances[i][k] + distances[k][j];
            }
        }
    }

    // Print the shortest distances matrix
    printShortestDistances(distances, V);
}

int main() {
    int V; // Number of vertices
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    std::vector<std::vector<int>> graph(V, std::vector<int>(V));

    std::cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            std::cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
                graph[i][j] = INF; // Set the value to INF if there is no direct edge
        }
    }

    floydWarshallAlgorithm(graph, V);

    return 0;
}
