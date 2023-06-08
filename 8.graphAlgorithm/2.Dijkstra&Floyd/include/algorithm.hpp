#include"../include/header.h"
#include"../include/graph.h"

/**
 * @brief dijkstra算法(单源)
 * @param graph 图
 * @param start_vertex 起点
 * @param finish_vertex 终点
 *
 * @return result 1->(n-1): 节点, n: 总长
 * @note 1. 每次从未标记的节点中选择距离出发点最近的节点, 收录到最优路径中
 *       2. 计算刚加入节点A的临近节点B的距离, 不包含标记的节点, 若节点A的距离加上A到B的距离小于节点B的距离, 则更新节点B的距离和前面点
 */
std::vector<INDEX_> dijkstra(::Graph graph, INDEX_ start_vertex, INDEX_ finish_vertex){

}

/**
 * @brief floyd算法(多源)
 * @param graph 图
 *
 * @return std::vector<std::vector<WEIGHT_> >
 */
std::vector<std::vector<WEIGHT_> > floyd(::Graph graph) {
    std::vector<std::vector<WEIGHT_> > result(graph.getNumVertices(),
                                              std::vector<WEIGHT_>(graph.getNumVertices(), INT_MAX));
    for (int i = 0; i < graph.getNumVertices(); i++) {
        for (int j = 0; j < graph.getNumVertices(); j++) {
            if (i == j) {
                result[i][j] = 0;
            } else if (graph.ifLinked(i, j)) {
                result[i][j] = graph.getWeight(i, j);
            }
        }
    }
    for (int k = 0; k < graph.getNumVertices(); k++) {
        for (int i = 0; i < graph.getNumVertices(); i++) {
            for (int j = 0; j < graph.getNumVertices(); j++) {
                if (result[i][k] != INT_MAX && result[k][j] != INT_MAX && result[i][k] + result[k][j] < result[i][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
    return result;
}