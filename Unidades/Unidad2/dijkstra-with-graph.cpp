#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>

using namespace std;

// Function to find the vertex with the minimum distance value
int findMinDistanceVertex(const vector<int>& distances, const vector<bool>& visited) {
    int minDistance = numeric_limits<int>::max();
    int minVertex = -1;

    for (int i = 0; i < distances.size(); ++i) {
        if (!visited[i] && distances[i] < minDistance) {
            minDistance = distances[i];
            minVertex = i;
        }
    }

    return minVertex;
}

// Function to perform Dijkstra's algorithm on the given adjacency matrix
vector<int> dijkstra(const vector<vector<int>>& graph, int startVertex) {
    int numVertices = graph.size();

    // Initialize distances and visited arrays
    vector<int> distances(numVertices, numeric_limits<int>::max());
    vector<bool> visited(numVertices, false);

    // Distance of start vertex from itself is 0
    distances[startVertex] = 0;

    for (int i = 0; i < numVertices - 1; ++i) {
        // Find the vertex with the minimum distance value
        int currentVertex = findMinDistanceVertex(distances, visited);

        // Mark the current vertex as visited
        visited[currentVertex] = true;

        // Update distances of adjacent vertices
        for (int j = 0; j < numVertices; ++j) {
            if (!visited[j] && graph[currentVertex][j] != 0 &&
                distances[currentVertex] != numeric_limits<int>::max() &&
                distances[currentVertex] + graph[currentVertex][j] < distances[j]) {
                distances[j] = distances[currentVertex] + graph[currentVertex][j];
            }
        }
    }

    return distances;
}

int main() {
    
    int V = 9;
    char charKey = 'A';

    unordered_map<int, char> myMap;
    for (int i = 0 ; i <= V ; ++i) {
        myMap[i] = charKey;
        ++charKey;
    }
    // Range-based for loop
    for (const auto& pair : myMap) {
        const char& key = pair.second;
        int value = pair.first;
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    // Example adjacency matrix
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 11, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 2, 0, 0, 0, 6, 7, 0}
    };

    int startVertex = 0;

    // Call the Dijkstra's algorithm
    vector<int> distances = dijkstra(graph, startVertex);

    // Print the distances
    cout << "Shortest distances from vertex " << startVertex << " to all other vertices:" << endl;
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Vertex " << myMap[i] << ": " << distances[i] << endl;
    }

    return 0;
}
