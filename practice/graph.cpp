#include <iostream>
#include <unordered_map>
#include <list>
#include <unordered_set>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjacencyList;
    // content of adjacencyList: 
    // {
    //  "vertex1": [neighbor1, neighbor2, ...], 
    //  "vertex2": [neighbor1, neighbor2, ...], ...
    // }
    bool isDirected;

    Graph() : isDirected(false) {}

    Graph(bool isDirected) : isDirected(isDirected) {}

    bool isEmpty() const {
        return adjacencyList.empty();
    }

    bool isGraphDirected() const {
        return isDirected;
    }

    bool vertexExists(int vertex) const {
        // Manual check if vertex exists in adjacencyList using a loop
        for (const auto& i : adjacencyList) {
            //  "vertex1": [neighbor1, neighbor2, ...]
            // i.first = vertex1
            // i.second = [neighbor1, neighbor2, ...]
            // i.second[i] = neighbor[i]
            if (i.first == vertex) {
                return true;
            }
        }
        return false;
    }

    bool hasNeighbor(const list<int>& neighbors, int vertex) const {
        // Manual check if vertex is a neighbor in the list
        for (int neighbor : neighbors) {
            if (neighbor == vertex) {
                return true;
            }
        }
        return false;
    }

    void addVertex(int vertex) {
        // Check if the vertex already exists
        if (!vertexExists(vertex)) {
            adjacencyList[vertex] = list<int>();
        }
    }

    void addEdge(int vertex1, int vertex2) {
        // Add vertices if they don't exist
        if (!vertexExists(vertex1)) {
            adjacencyList[vertex1] = list<int>();
        }
        if (!vertexExists(vertex2)) {
            adjacencyList[vertex2] = list<int>();
        }

        // Add edge
        adjacencyList[vertex1].push_back(vertex2);
        if (!isDirected) {
            adjacencyList[vertex2].push_back(vertex1); // Only for undirected graphs
        }
    }

    void removeVertex(int vertex) {
        // Erase vertex and its connections manually
        adjacencyList.erase(vertex);
        for (auto& pair : adjacencyList) {
            pair.second.remove(vertex);
        }
    }

    void removeEdge(int vertex1, int vertex2) {
        // Remove edge manually
        if (vertexExists(vertex1) && vertexExists(vertex2)) {
            adjacencyList[vertex1].remove(vertex2);
            if (!isDirected) {
                adjacencyList[vertex2].remove(vertex1);
            }
        }
    }

    int numVertices() const {
        return adjacencyList.size();
    }

    int numEdges() const {
        int count = 0;
        for (const auto& pair : adjacencyList) {
            count += pair.second.size();
        }
        if (!isDirected) {
            count /= 2; // For undirected graphs, each edge is counted twice
        }
        return count;
    }

    int indegree(int vertex) const {
        int count = 0;
        for (const auto& pair : adjacencyList) {
            if (hasNeighbor(pair.second, vertex)) {
                count++;
            }
        }
        return count;
    }

    int outdegree(int vertex) const {
        if (vertexExists(vertex)) {
            return adjacencyList.at(vertex).size();
        }
        return 0;
    }

    int degree(int vertex) const {
        return indegree(vertex) + outdegree(vertex);
    }

    unordered_set<int> neighbours(int vertex) const {
        unordered_set<int> result;
        if (vertexExists(vertex)) {
            for (const auto& neighbor : adjacencyList.at(vertex)) {
                result.insert(neighbor);
            }
        }
        return result;
    }

    bool neighbour(int vertex1, int vertex2) const {
        if (vertexExists(vertex1)) {
            return hasNeighbor(adjacencyList.at(vertex1), vertex2);
        }
        return false;
    }

    
};

int main() {
    Graph g;

    // Manually add vertices and edges
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    // To add a new vertex and edge manually
    g.addEdge(4, 2); // Adding vertex 4 connected to vertex 2

    // To remove an edge manually
    g.removeEdge(1, 3); // Remove edge between vertex 1 and 3

    // To remove a vertex manually
    g.removeVertex(2); // Remove vertex 2

    // Accessing number of vertices and edges
    cout << "Number of vertices: " << g.numVertices() << endl;
    cout << "Number of edges: " << g.numEdges() << endl;

    return 0;
}
