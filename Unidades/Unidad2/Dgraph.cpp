#include <iostream>
#include <vector>

class DirectedGraph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjMatrix;

public:
    DirectedGraph(int vertices) : numVertices(vertices) {
        adjMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    void addEdge(int src, int dest) {
        if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices) {
            adjMatrix[src][dest] = 1;
        }
    }

    void printGraph() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
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
