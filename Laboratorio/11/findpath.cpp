#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Function to add an edge between vertices u and v
void addEdge(vector<vector<int>>& graph, int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

// Function to print the adjacency matrix
void printGraph(const vector<vector<int>>& graph) {
    cout << "Adjacency Matrix:\n";
    for (const auto& row : graph) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << '\n';
    }
}

// Function to perform breadth-first search and find a path between two vertices
vector<int> findPath(const vector<vector<int>>& graph, int startVertex, int endVertex) {
    int numVertices = graph.size();
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);

    // Create a queue for BFS
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    // Perform BFS
    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();

        // Check if we have reached the end vertex
        if (currentVertex == endVertex) {
            // Reconstruct the path by backtracking from the end vertex to the start vertex
            vector<int> path;
            int vertex = endVertex;
            while (vertex != -1) {
                path.push_back(vertex);
                vertex = parent[vertex];
            }
            reverse(path.begin(), path.end());
            return path;
        }

        // Explore neighbors of the current vertex
        for (int neighbor = 0; neighbor < numVertices; ++neighbor) {
            if (graph[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                parent[neighbor] = currentVertex;
            }
        }
    }

    // No path found
    return {};
}


int main() {
    int V = 8; // Number of vertices
    // Create an empty adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, 0));

    /*
    0 = A
    1 = B
    2 = C
    3 = D
    4 = E
    5 = F
    6 = G
    7 = H 
    */
    addEdge(graph,0,1);
    addEdge(graph,0,2);
    addEdge(graph,1,3);
    addEdge(graph,1,4);
    addEdge(graph,1,5);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    addEdge(graph,2,6);
    addEdge(graph,3,4);
    addEdge(graph,4,5);
    addEdge(graph,4,7);
    addEdge(graph,5,6);
    addEdge(graph,5,7);

    // Print the adjacency matrix
    printGraph(graph);

   /*
    1 = B
    7 = H 
    */
    
    // Call the findPath function
    vector<int> path = findPath(graph, 1, 7);
    // Print the path
    if (!path.empty()) {
        cout << "Path found: ";
        for (int vertex : path) {
            cout << vertex << " ";
        }
        cout << endl;
    } else {
        cout << "No path found." << endl;
    }
    return 0;
}
