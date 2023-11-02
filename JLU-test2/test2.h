#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Test2_Graph {
private:
    vector<vector<int>> adjMatrix;

public:
    vector<bool> visited;
    Test2_Graph(const vector<vector<int>>& matrix) {
        adjMatrix = matrix;
        int numNodes = matrix.size();
        visited.resize(numNodes, false);
    }

    void dfs(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < adjMatrix[node].size(); i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                dfs(i);
            }
        }
    }

    void dfsTraversal() {
        for (int i = 0; i < adjMatrix.size(); i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
    }

    void bfs(int node) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int currNode = q.front();
            q.pop();
            cout << currNode << " ";

            for (int i = 0; i < adjMatrix[currNode].size(); i++) {
                if (adjMatrix[currNode][i] == 1 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void bfsTraversal() {
        for (int i = 0; i < adjMatrix.size(); i++) {
            if (!visited[i]) {
                bfs(i);
            }
        }
    }

    void recursiveTraversal(int node) {
        visited[node] = true;
        cout << node << " ";

        for (int i = 0; i < adjMatrix[node].size(); i++) {
            if (adjMatrix[node][i] == 1 && !visited[i]) {
                recursiveTraversal(i);
            }
        }
    }

    void recursiveDFS() {
        for (int i = 0; i < adjMatrix.size(); i++) {
            if (!visited[i]) {
                recursiveTraversal(i);
            }
        }
    }
};

int test2_main() {
    vector<vector<int>> matrix = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 1, 0}
    };

    Test2_Graph graph(matrix);

    cout << "DFS traversal: ";
    graph.dfsTraversal();
    cout << endl;

    // Reset visited array
    fill(graph.visited.begin(), graph.visited.end(), false);

    cout << "BFS traversal: ";
    graph.bfsTraversal();
    cout << endl;

    // Reset visited array
    fill(graph.visited.begin(), graph.visited.end(), false);

    cout << "Recursive DFS traversal: ";
    graph.recursiveDFS();
    cout << endl;

    return 0;
}