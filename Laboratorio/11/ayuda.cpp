#include <iostream>
#include <vector>
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
void printGraphVert(const vector<vector<int>>& graph, int vert) {
    cout << "Adjacency Matrix:\n";
    for ( int i = 0; i < vert ; i++) {
        for ( int j = 0 ; j < vert ; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    // for (const auto& row : graph) {
    //     for (int val : row) {
    //         cout << val << " ";
    //     }
    //     cout << '\n';
    // }
}

int main() {
    int V; // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create an empty adjacency matrix
    vector<vector<int>> graph(V, vector<int>(V, 0));

    graph[0][1] = 1;
    graph[0][3] = 1;
    addEdge(graph,2,3);

    // Print the adjacency matrix
    printGraph(graph);
    printGraphVert(graph,V);

    return 0;
}
