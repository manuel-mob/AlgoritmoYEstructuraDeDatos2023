#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>
#include <string>

using namespace std;

const int INF = numeric_limits<int>::max();

int main() {

    int V = 0;

    unordered_map<string, int> myMapStringInt;
    myMapStringInt["string1"] = 1;
    myMapStringInt["string2"] = 2;
    myMapStringInt["string3"] = 3;

    // Range-based for loop
    for (const auto& pair : myMapStringInt) {
        const string& key = pair.first;
        int value = pair.second;
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    // Iterator-based loop
    for (auto it = myMapStringInt.begin(); it != myMapStringInt.end(); ++it) {
        const string& key = it->first;
        int value = it->second;
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    unordered_map<int, string> myMapIntString;
    myMapIntString[1] = "String 1";
    myMapIntString[2] = "String 2";
    myMapIntString[3] = "String 3";
        // Range-based for loop
    for (const auto& pair : myMapIntString) {
        int key = pair.first;
        const string& value = pair.second;
        cout << "Key: " << key << ", Value: " << value << endl;
    }

    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0, 0},
        {0, 8, 0, 7, 0, 4, 0},
        {0, 0, 7, 0, 9, 14, 0},
        {0, 0, 0, 9, 0, 10, 0},
        {0, 0, 4, 14, 10, 0, 2},
        {0, 0, 0, 0, 0, 2, 0}
    };

    V = graph.size();
    for (int i = 0; i < V; ++i) {
        cout << "Vertice " << i << ":";
        for (int j = 0; j < V; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    //Directed Graph
    cout << endl << "Directed Graph" << endl;
    vector<vector<int>> graphDirected  = {
        {0, 2, INF, 1, INF},
        {INF, 0, 4, INF, 5},
        {INF, INF, 0, INF, INF},
        {INF, INF, 2, 0, INF},
        {INF, INF, INF, 3, 0}
    };

    V = graphDirected.size();
    for (int i = 0; i < V; ++i) {
        cout << "Vertice " << i << ":";
        for (int j = 0; j < V; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    string filename = "data.csv";
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        getline(file, line); // Skip the header line

        while (getline(file, line)) {
            stringstream ss(line);
            string data1, data2;
            getline(ss, data1, ',');
            getline(ss, data2, ',');

            cout << "Data1: " << data1 << " / Data2: " << data2 << endl; 
        }

        file.close();
    }
    else {
        cout << "Failed to open file: " << filename << endl;
    }

    return 0;

}