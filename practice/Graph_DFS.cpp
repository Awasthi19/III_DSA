#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

unordered_map<int, list<int>> build_adjacencyList(){

    // Number of vertices
    int n;  
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Adjacency List initialization
    unordered_map<int, list<int>> adj;

    // Adding edges to the graph
    int totalEdges;
    cout << "Enter the total number of edges: ";
    cin >> totalEdges;

    // Adding edges to the graph
    for (int i = 0; i < totalEdges; i++) {
        int vertex1, vertex2;
        cout << "Enter the vertices for edge " << i + 1 << ": ";
        cin >> vertex1 >> vertex2;
        adj[vertex1].push_back(vertex2);
        adj[vertex2].push_back(vertex1); 
    }
    return adj;
}

void print_adjacencyList(unordered_map<int, list<int>> adj) {
    cout << "Adjacency List: " << endl;
    //if adj = {1: [2, 3], 2: [1, 3], 3: [1, 2]}
    // adj[1] = [2, 3]
    for (auto i : adj) {
        //i={1, [2, 3]}
        cout << i.first << " -> ";
        for (auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }
}


void DFS(unordered_map<int, list<int>> &adj,unordered_map<int,bool> &visited,int vertex,vector<int> &vertexInDFS){
    visited[vertex]=true;
    vertexInDFS.push_back(vertex);
    for (auto i:adj[vertex]){
        if(!visited[i]){
            DFS(adj,visited,i,vertexInDFS);
        }
    }
}

int main() {

    unordered_map<int, list<int>> adj;
    adj = build_adjacencyList();
    print_adjacencyList(adj);

    unordered_map<int,bool> visited;
    // visited = {1: False, 2: False, 3: False}
    // visited[1] = False

    vector<int> vertexInDFS;
    // for loop for covering disconnected vertex in the graph else it will not 
    //traverse disconnected graph
    for (auto i : adj) {
        // i = {1,[2,3]}
        //i.first = 1
        if (!visited[i.first]) {
            DFS(adj, visited, i.first, vertexInDFS);
        }
    }
    cout << "DFS traversal: ";
    for (auto vertex : vertexInDFS) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
