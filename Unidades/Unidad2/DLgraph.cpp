#include <iostream>
#include <vector>

using namespace std;

class DirectedGraph {
private:
    int numVertices;
    vector<vector<int>> adjList;

public:
    DirectedGraph(int vertices) : numVertices(vertices) {
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjList[src].push_back(dest);
        }
    }

    void printGraph() {
        cout << "Adjacency List:" << endl;
        for (int i = 0; i < numVertices; ++i) {
            cout << "Vertex " << i << ": ";
            for (const auto& neighbor : adjList[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    DirectedGraph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}
