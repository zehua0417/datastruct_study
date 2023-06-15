#ifndef TOP0LOGICAL_SORT_HPP_
#define TOP0LOGICAL_SORT_HPP_
#include"../../2.Dijkstra&Floyd/include/header.h"
#include"../../2.Dijkstra&Floyd/include/weightedEdge.hpp"
#include"../../2.Dijkstra&Floyd/include/weightedGraph.hpp"
#include"../../2.Dijkstra&Floyd/include/weightedDirectedGraph.hpp"

template<typename T>
std::vector<int> topologicalSort(const WeightedDirectedGraph<T>& graph) {
    std::vector<int> indegree(graph.numberVertices(), 0);
    std::vector<int> result;

    // 计算每个顶点的入度
    for (int v = 0; v < graph.numberVertices(); ++v) {
        for (const auto& edge : graph.matrix[v]) {
            indegree[edge.linked_vertex]++;
        }
    }

    // 使用队列来进行拓扑排序
    std::queue<int> q;
    for (int v = 0; v < graph.numberVertices(); ++v) {
        if (indegree[v] == 0) {
            q.push(v);
        }
    }

    while (!q.empty()) {
        int vertex = q.front();
        q.pop();
        result.push_back(vertex);

        // 减少与当前顶点相邻顶点的入度
        for (const auto& edge : graph.matrix[vertex]) {
            indegree[edge.linked_vertex]--;
            if (indegree[edge.linked_vertex] == 0) {
                q.push(edge.linked_vertex);
            }
        }
    }

    return result;
}

#endif