/*
 * @filename algorithm
 * @author lihuax
 * @description kruskal_algorithm for graph -> mst
 */
#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP
#include"../include/header.h"
#include"../include/graph.h"
#include"../include/tree.hpp"

template<typename T>
Tree<T>* kruskal_algorithm(const Graph& graph);

void printMST(const Graph& graph, const std::vector<std::pair<INDEX_, WEIGHT_>>& mst);


void printMST(const Graph& graph, const std::vector<std::pair<INDEX_, WEIGHT_>>& mst) {
    std::cout << "Minimum Spanning Tree (Prim's Algorithm):" << std::endl;
    WEIGHT_ totalWeight = 0;

    for (const auto& edge : mst) {
        INDEX_ src = edge.first;
        INDEX_ dest = edge.second;
        WEIGHT_ weight = graph.getWeight(src, dest);

        std::cout << src << " - " << dest << ": " << weight << std::endl;
        totalWeight += weight;
    }

    std::cout << "Total weight of the MST: " << totalWeight << std::endl;
}

// kruskal_algorithm for graph -> tree::mst
template<typename T>
Tree<T>* kruskal_algorithm(const Graph& graph) {
    struct Edge {
        INDEX_ src;
        INDEX_ dest;
        WEIGHT_ weight;

        Edge(INDEX_ s, INDEX_ d, WEIGHT_ w) : src(s), dest(d), weight(w) {}
    };

    // 构建边集合
    std::vector<Edge> edges;
    for (INDEX_ src = 0; src < graph.getNumVertices(); src++) {
        for (const auto& dest : graph.getLinked(src)) {
            WEIGHT_ weight = graph.getWeight(src, dest);
            edges.emplace_back(src, dest, weight);
        }
    }

    // 按照权值升序排序边集合
    std::sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    // 使用并查集来判断两个顶点是否在同一连通分量中
    std::vector<INDEX_> parent(graph.getNumVertices());
    for (INDEX_ i = 0; i < graph.getNumVertices(); i++) {
        parent[i] = i;
    }

    // 构建最小生成树
    Tree<T>* mst = new Tree<T>();
    for (const auto& edge : edges) {
        INDEX_ src = edge.src;
        INDEX_ dest = edge.dest;

        // 检查是否在同一连通分量中
        INDEX_ src_root = src;
        while (src_root != parent[src_root]) {
            src_root = parent[src_root];
        }

        INDEX_ dest_root = dest;
        while (dest_root != parent[dest_root]) {
            dest_root = parent[dest_root];
        }

        if (src_root != dest_root) {
            // 加入最小生成树
            mst->insert(edge.weight, edge.src);
            parent[src_root] = dest_root;
        }
    }

    return mst;
}
#endif //ALGORITHM_HPP
