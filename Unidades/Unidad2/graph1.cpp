#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src);
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < adjacencyList[i].size(); j++) {
                cout << adjacencyList[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int numVertices = 5;
    Graph graph(numVertices);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}
