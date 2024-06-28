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

    Graph() {
        isDirected = false;
    }

    Graph(bool isDirected) {
        this->isDirected = isDirected;
    } 

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
            // adjacencyList[vertex1] = [neighbor1, neighbor2, ...] remove vertex2 from the list
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

    bool hasNeighbor(const list<int>& neighbors, int vertex) const {
        // Manual check if vertex is a neighbor in the list
        for (int neighbor : neighbors) {
            if (neighbor == vertex) {
                return true;
            }
        }
        return false;
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
            int count = 0;
            for (const auto& pair : adjacencyList) {
                if (pair.first == vertex) {
                    count = pair.second.size();
                    break;
                }
            }
            return count;
        }
        return 0;
    }

    int degree(int vertex) const {
        return indegree(vertex) + outdegree(vertex);
    }

    list<int> neighbours(int vertex) const {
        list<int> result;
        if (vertexExists(vertex)) {
            for (const auto& pair : adjacencyList) {
                if (pair.first == vertex) {
                    for (const auto& neighbor : pair.second) {
                        result.push_back(neighbor);
                    }
                    break;
                }
            }
        }
        return result;
    }

    bool neighbour(int vertex1, int vertex2) const {
        if (vertexExists(vertex1)) {
            for (const auto& pair : adjacencyList) {
                if (pair.first == vertex1) {
                    return hasNeighbor(pair.second, vertex2);
                }
            }
        }
        return false;
    }

    
};

int main() {
    // Create a directed graph
    Graph directedGraph(true);

    // Add vertices
    directedGraph.addVertex(1);
    directedGraph.addVertex(2);
    directedGraph.addVertex(3);
    directedGraph.addVertex(4);

    // Add edges
    directedGraph.addEdge(1, 2);
    directedGraph.addEdge(2, 3);
    directedGraph.addEdge(3, 4);
    directedGraph.addEdge(4, 1);

    // Print the number of vertices and edges
    cout << "Number of vertices: " << directedGraph.numVertices() << endl;
    cout << "Number of edges: " << directedGraph.numEdges() << endl;

    // Check if a vertex exists
    int vertex = 3;
    if (directedGraph.vertexExists(vertex)) {
        cout << "Vertex " << vertex << " exists in the graph." << endl;
    } else {
        cout << "Vertex " << vertex << " does not exist in the graph." << endl;
    }

    // Check if an edge exists
    int vertex1 = 2;
    int vertex2 = 4;
    if (directedGraph.neighbour(vertex1, vertex2)) {
        cout << "There is an edge between " << vertex1 << " and " << vertex2 << "." << endl;
    } else {
        cout << "There is no edge between " << vertex1 << " and " << vertex2 << "." << endl;
    }

    // Print the neighbors of a vertex
    int targetVertex = 1;
    list<int> neighbors = directedGraph.neighbours(targetVertex);
    cout << "Neighbors of vertex " << targetVertex << ": ";
    for (int neighbor : neighbors) {
        cout << neighbor << " ";
    }
    cout << endl;

    return 0;
}