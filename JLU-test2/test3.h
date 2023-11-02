#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Test3_Graph {
private:
    int numVertices;
    vector<vector<int>> adjacencyMatrix;

public:
    Test3_Graph(int numVertices) : numVertices(numVertices) {
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int source, int destination, int weight) {
        adjacencyMatrix[source][destination] = weight;
        adjacencyMatrix[destination][source] = weight;
    }

    vector<pair<int, int>> prim() {
        vector<bool> visited(numVertices, false);
        vector<pair<int, int>> mst;

        visited[0] = true;

        for (int count = 0; count < numVertices - 1; ++count) {
            int minWeight = INT_MAX;
            int u, v;

            for (int i = 0; i < numVertices; ++i) {
                if (visited[i]) {
                    for (int j = 0; j < numVertices; ++j) {
                        if (!visited[j] && adjacencyMatrix[i][j] && adjacencyMatrix[i][j] < minWeight) {
                            minWeight = adjacencyMatrix[i][j];
                            u = i;
                            v = j;
                        }
                    }
                }
            }

            visited[v] = true;
            mst.push_back(make_pair(u, v));
        }

        return mst;
    }

    struct Edge {
        int source, destination, weight;
    };

    static bool compareEdges(const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    }

    int findParent(vector<int>& parent, int i) {
        if (parent[i] == i)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, int x, int y) {
        int xRoot = findParent(parent, x);
        int yRoot = findParent(parent, y);
        parent[yRoot] = xRoot;
    }

    vector<pair<int, int>> kruskal() {
        vector<pair<int, int>> mst;
        vector<Edge> edges;

        for (int i = 0; i < numVertices; ++i) {
            for (int j = i + 1; j < numVertices; ++j) {
                if (adjacencyMatrix[i][j] != 0) {
                    Edge edge;
                    edge.source = i;
                    edge.destination = j;
                    edge.weight = adjacencyMatrix[i][j];
                    edges.push_back(edge);
                }
            }
        }

        sort(edges.begin(), edges.end(), compareEdges);

        vector<int> parent(numVertices);
        for (int i = 0; i < numVertices; ++i)
            parent[i] = i;

        int edgeCount = 0;
        for (const auto& edge : edges) {
            int x = findParent(parent, edge.source);
            int y = findParent(parent, edge.destination);

            if (x != y) {
                mst.push_back(make_pair(edge.source, edge.destination));
                unionSets(parent, x, y);
                edgeCount++;
            }

            if (edgeCount == numVertices - 1)
                break;
        }

        return mst;
    }
};

int test3_main() {
    Test3_Graph graph(5);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 0);
    graph.addEdge(0, 3, 0);
    graph.addEdge(0, 4, 0);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 0);
    graph.addEdge(1, 4, 0);
    graph.addEdge(2, 3, 1);
    graph.addEdge(2, 4, 0);
    graph.addEdge(3, 4, 1);

    cout << "Minimum Spanning Tree using Prim's algorithm:" << endl;
    vector<pair<int, int>> mstPrim = graph.prim();
    for (const auto& edge : mstPrim) {
        cout << edge.first << " - " << edge.second << endl;
    }

    cout << endl;

    cout << "Minimum Spanning Tree using Kruskal's algorithm:" << endl;
    vector<pair<int, int>> mstKruskal = graph.kruskal();
    for (const auto& edge : mstKruskal) {
        cout << edge.first << " - " << edge.second << endl;
    }
    return 0;
}