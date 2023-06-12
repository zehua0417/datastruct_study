#ifndef PRIM_KRUSKAL_HPP_
#define PRIM_KRUSKAL_HPP_
#include"../include/header.h"
#include"../include/unionFind.h"


template<typename T>
WeightedGraph<T> primAlgorithm(const WeightedGraph<T>& graph) {
    // 无向图节点的数量
    int verticesCount = graph.numberVertices();

    // 父节点数组用于存储每个节点的父节点
    std::vector<int> parent(verticesCount, -1);

    // key值，用于选取具有最小权值的边
    std::vector<T> key(verticesCount, std::numeric_limits<T>::max());

    // 最小优先级队列，用于选取具有最小权值的边
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<>> priorityQueue;

    // 从第一个节点开始，它的key值为0
    key[0] = 0;
    priorityQueue.push({0, 0});

    // 标记数组，如果节点i被标记，标记[i]将为true
    std::vector<bool> inMST(verticesCount, false);

    while (!priorityQueue.empty()) {
        // 选取具有最小权值的边
        int minVertex = priorityQueue.top().second;
        priorityQueue.pop();

        // 将该节点添加到MST中
        inMST[minVertex] = true;

        // 遍历所有相邻的节点
        for (const auto& edge : graph.matrix[minVertex]) {
            int v = edge.linked_vertex;
            T weight = edge.weight;
            // 如果v不在MST中，并且权值小于key[v]
            if (!inMST[v] && key[v] > weight) {
                // 更新key值为权值
                key[v] = weight;
                priorityQueue.push({key[v], v});
                parent[v] = minVertex;
            }
        }
    }

    // 创建最小生成树
    WeightedGraph<T> mst(verticesCount);
    for (int i = 1; i < verticesCount; ++i)
        mst.insertEdge(parent[i], {i, key[i]});

    return mst;
}

template<typename T>
WeightedGraph<T> kruskalAlgorithm(WeightedGraph<T>& graph) {
    // 创立一个新的空图来保存最小生成树
    WeightedGraph<T> mst(graph.numberVertices());

    // 将所有的边存储到一个 vector 中
    std::vector<std::pair<T, std::pair<int, int>>> edges;
    for(int u = 0; u < graph.numberVertices(); ++u) {
        for(auto& edge : graph.matrix[u]) {
            int v = edge.linked_vertex;
            T w = edge.weight;
            if(u < v) // 避免添加重复的边
                edges.push_back({w, {u, v}});
        }
    }

    // 将所有的边按照权值从小到大排序
    std::sort(edges.begin(), edges.end());

    // 创建并查集
    UnionFind uf(graph.numberVertices());

    // 遍历每一条边
    for(auto& edge : edges) {
        T w = edge.first;
        int u = edge.second.first, v = edge.second.second;

        // 检查这条边的两个顶点是否属于同一棵树
        if(uf.find(u) != uf.find(v)) {
            // 如果不是，添加这条边到最小生成树，并合并两棵树
            mst.insertEdge(u, {v, w});
            mst.insertEdge(v, {u, w});
            uf.unionSet(u, v);
        }
    }

    return mst;
}


#endif // PRIM_KRUSKAL_HPP_