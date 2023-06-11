#ifndef PRIM_KRUSKAL_HPP_
#define PRIM_KRUSKAL_HPP_

#include"../include/header.h"
#include"../include/weightedGraph.hpp"
#include"../include/tree.hpp"

// Prim算法
    template<typename T>
    Tree<T> prim(const WeightedGraph<T>& graph) {
        int numVertices = graph.numberVertices();
        std::vector<bool> visited(numVertices, false);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> pq;

        // 根据顶点0开始生成最小生成树
        pq.push({ 0, 0 });
        Tree<T> minimumSpanningTree;
        while (!pq.empty()) {
            int vertex = pq.top().second;
            T weight = pq.top().first;
            pq.pop();

            if (visited[vertex])
                continue;

            visited[vertex] = true;
            if (vertex != 0) {
                int parentVertex = -1;
                T minWeight = std::numeric_limits<T>::max();
                for (int i = 0; i < numVertices; i++) {
                    if (visited[i]) {
                        for (const auto& edge : graph.matrix[vertex]) {
                            if (edge.linked_vertex == i && edge.weight < minWeight) {
                                parentVertex = i;
                                minWeight = edge.weight;
                                break;
                            }
                        }
                    }
                }
                if (parentVertex != -1) {
                    auto parent = minimumSpanningTree.findNode(minimumSpanningTree.getRoot(), parentVertex);
                    if (parent != nullptr) {
                        minimumSpanningTree.insertNode(parent, vertex);
                    }
                }
            } else {
                minimumSpanningTree.setRoot(vertex);
            }

            for (const auto& edge : graph.matrix[vertex]) {
                if (!visited[edge.linked_vertex])
                    pq.push({ edge.weight, edge.linked_vertex });
            }
        }

        return minimumSpanningTree;
    }

#endif // PRIM_KRUSKAL_HPP_