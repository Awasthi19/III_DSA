#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
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


void BFS(unordered_map<int, list<int>> &adj,unordered_map<int,bool> &visited,int vertex,vector<int> &vertexInBFS){
    queue<int> q;
    q.push(vertex);

    visited[vertex]=true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        vertexInBFS.push_back(front);
        for (auto i:adj[front]){
            if (!visited[i]){
                q.push(i);
                visited[i]= true;
            }
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

    vector<int> vertexInBFS;
    // for loop for covering disconnected vertex in the graph else it will not 
    //traverse disconnected graph
    for (auto i : adj) {
        // i = {1,[2,3]}
        //i.first = 1
        if (!visited[i.first]) {
            BFS(adj, visited, i.first, vertexInBFS);
        }
    }
    cout << "BFS traversal: ";
    for (auto vertex : vertexInBFS) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}
