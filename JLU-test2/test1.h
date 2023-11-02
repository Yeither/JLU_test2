//
// Created by Administrator on 2023/9/24.
//
//例如，如果我们有5个用户A、B、C、D和E。A和B是朋友，B和C也是朋友，D和E是朋友，使用图论来模型化社交网络,进行社交网络中的朋友推荐
#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>

using namespace std;

class Test1_Graph {
private:
    int numVertices;
    vector<vector<int>> adjLists;

public:
    Test1_Graph(int vertices) : numVertices(vertices) {
        adjLists.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); // For undirected graph
    }

    unordered_set<int> getFriendsOfFriends(int vertex) {
        unordered_set<int> directFriends(adjLists[vertex].begin(), adjLists[vertex].end());
        unordered_set<int> friendsOfFriends;

        for (int friendVertex : adjLists[vertex]) {
            for (int friendOfFriend : adjLists[friendVertex]) {
                if (directFriends.find(friendOfFriend) == directFriends.end() && friendOfFriend != vertex) {
                    friendsOfFriends.insert(friendOfFriend);
                }
            }
        }

        return friendsOfFriends;
    }

    void run(){

        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(3, 4);

        unordered_set<int> recommendations = getFriendsOfFriends(0);

        cout << "Friend recommendations for user 0: ";
        for (int rec : recommendations) {
            cout << rec << " ";
        }
        cout << endl;

    }
};

class Test1_Graph2 {
private:
    vector<vector<int>> adjMatrix;

public:
    Test1_Graph2(int numVertices) {
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j) {
        adjMatrix[i][j] = 1;
        adjMatrix[j][i] = 1; // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < adjMatrix.size(); i++) {
            for (int j = 0; j < adjMatrix[i].size(); j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void run1(){
        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(3, 4);
        printGraph();
    }
};

class Test1_Graph3 {
private:
    int numVertices;
    vector<list<int>> adjLists;

public:
    Test1_Graph3(int vertices) : numVertices(vertices) {
        adjLists.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjLists[src].push_back(dest);
        adjLists[dest].push_back(src); // For undirected graph
    }

    void printGraph() {
        for (int v = 0; v < numVertices; v++) {
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto x : adjLists[v])
                cout << "-> " << x;
            printf("\n");
        }
    }

    void run3(){
        addEdge(0, 1);
        addEdge(1, 2);
        addEdge(3, 4);
        printGraph();
    }
};

int test1_main() {
    Test1_Graph g(5);
    Test1_Graph2 g2(5);
    Test1_Graph3 g3(5);
    g.run();
    g2.run1();
    g3.run3();
    return 0;
}