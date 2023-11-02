#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>

using namespace std;

const int numVertices = 5;

void dijkstraShortestPath(vector<vector<int>>& adjacencyMatrix, int source) {
    vector<int> distance(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);
    distance[source] = 0;

    for (int count = 0; count < numVertices - 1; ++count) {
        int u = -1;
        int minDistance = INT_MAX;

        // Find the vertex with the minimum distance
        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && distance[v] < minDistance) {
                u = v;
                minDistance = distance[v];
            }
        }

        if (u == -1)
            break;

        visited[u] = true;

        // Update distances of adjacent vertices
        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && adjacencyMatrix[u][v] && distance[u] != INT_MAX &&
                distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + adjacencyMatrix[u][v];
            }
        }
    }

    // Print shortest paths and lengths from the source
    cout << "Shortest paths from vertex " << source << ":\n";
    for (int v = 0; v < numVertices; ++v) {
        cout << "To vertex " << v << ": ";
        if (distance[v] == INT_MAX)
            cout << "No path";
        else
            cout << distance[v];
        cout << endl;
    }
}
///////////////////////////////////////////////////////////////////////////

void stackShortestPath(vector<vector<int>>& adjacencyMatrix, int source) {
    vector<int> distance(numVertices, INT_MAX);
    vector<bool> visited(numVertices, false);
    vector<int> parent(numVertices, -1);
    stack<int> path;

    distance[source] = 0;
    visited[source] = true;
    path.push(source);

    while (!path.empty()) {
        int u = path.top();
        path.pop();

        for (int v = 0; v < numVertices; ++v) {
            if (!visited[v] && adjacencyMatrix[u][v] && distance[u] != INT_MAX &&
                distance[u] + adjacencyMatrix[u][v] < distance[v]) {
                distance[v] = distance[u] + adjacencyMatrix[u][v];
                parent[v] = u;
                visited[v] = true;
                path.push(v);
            }
        }
    }

    // Print shortest paths and lengths from the source
    cout << "Shortest paths from vertex " << source << ":\n";
    for (int v = 0; v < numVertices; ++v) {
        cout << "To vertex " << v << ": ";
        if (distance[v] == INT_MAX)
            cout << "No path";
        else
            cout << distance[v];
        cout << endl;
    }
}

int test4_main() {
    vector<vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 2, 0},
            {0, 0, 2, 0, 1},
            {0, 0, 0, 1, 0}
    };

    int source = 0; // Choose the source vertex

    dijkstraShortestPath(adjacencyMatrix, source);
    stackShortestPath(adjacencyMatrix, source);
    return 0;
}
