#ifndef GRAPHMATRIX_H
#define GRAPHMATRIX_H

#include <vector>

/*
 * @brief 邻接矩阵表示的图
 */
class GraphMatrix {
public:
    GraphMatrix(int num_vertices); // 构造函数

    void addEdge(int src, int dest); // 添加边
    void depthFirstTraversal(int start_vertex); // 深度优先遍历
    void breadthFirstTraversal(int start_vertex); // 广度优先遍历

private:
    int num_vertices; // 顶点数
    std::vector<std::vector<int>> adj_matrix; // 邻接矩阵
    void _depthFirstTraversal(int vertex, std::vector<bool>& visited); // 深度优先遍历
};

#endif  // GRAPHMATRIX_H
