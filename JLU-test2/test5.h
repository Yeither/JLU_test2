//
// Created by Administrator on 2023/10/13.
//
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 5 // 图的顶点数

// 使用Floyd算法计算任意两点间的最短路径和最短路径长度
void floyd(int graph[V][V]) {
    int dist[V][V];

    // 初始化dist数组为图的邻接矩阵
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // 通过中间顶点逐步更新最短路径
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != 0 && dist[k][j] != 0 && (dist[i][j] == 0 || dist[i][k] + dist[k][j] < dist[i][j])) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // 输出最短路径和最短路径长度
    cout << "shortest path and shortest path length between any two points：" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == 0) {
                cout << "INF\t";
            } else {
                cout << dist[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

// 使用递归方法计算任意两点间的最短路径和最短路径长度
void recursiveShortestPath(int graph[V][V], int src, int dest, vector<int>& path, vector<int>& shortestPath, int& minDist, int dist) {
    path.push_back(src);
    // 如果到达目标顶点，则更新最短路径长度和最短路径
    if (src == dest) {
        if (dist < minDist) {
            minDist = dist;
            shortestPath = path;
            return;
        }
    }
    else {
        // 递归计算从当前顶点到下一个顶点的最短路径
        for (int i = src; i < V; i++) {
            if (graph[src][i] != 0) {
                recursiveShortestPath(graph, i, dest, path, shortestPath, minDist, dist + graph[src][i]);
            }
        }
    }
}

int test5_main() {
    int graph[V][V] = {
            {0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 2, 0},
            {0, 0, 2, 0, 1},
            {0, 0, 0, 1, 0}
    };

    // 使用Floyd算法计算最短路径
    floyd(graph);

    // 使用递归方法计算最短路径长度和路径

    int src = 0; // 起始顶点
    int dest = 4; // 目标顶点
    int minDist = INT_MAX; // 最短路径长度
    vector<int> path; // 当前路径
    vector<int> shortestPath; // 最短路径

    recursiveShortestPath(graph, src, dest, path, shortestPath, minDist, 0);


    cout << "from " << src << " to " << dest << " shortest length " << minDist << endl;
    cout << "shortest path: ";
    for (int i = 0; i < shortestPath.size(); i++) {
        cout << shortestPath[i] << " ";
    }
    cout << endl;

    return 0;
}