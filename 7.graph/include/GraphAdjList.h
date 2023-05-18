#ifndef GRAPHADJLIST_H
#define GRAPHADJLIST_H

#include <vector>
#include <list>

/*
 * @brief 邻接表表示的图
 */
class GraphAdjList {
public:
    GraphAdjList(int num_vertices); // 构造函数

    void addEdge(int src, int dest); // 添加边
    void depthFirstTraversal(int start_vertex); // 深度优先遍历
    void breadthFirstTraversal(int start_vertex); // 广度优先遍历

private:
    int num_vertices; // 顶点数
    std::vector<std::list<int>> adj_list; // 邻接表
    void _depthFirstTraversal(int vertex, std::vector<bool>& visited); // 深度优先遍历
};

#endif  // GRAPHADJLIST_H
