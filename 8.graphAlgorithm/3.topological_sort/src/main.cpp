#include"../../2.Dijkstra&Floyd/include/header.h"
#include"../../2.Dijkstra&Floyd/include/weightedEdge.hpp"
#include"../../2.Dijkstra&Floyd/include/weightedGraph.hpp"
#include"../../2.Dijkstra&Floyd/include/weightedDirectedGraph.hpp"
#include"../include/topological_sort.hpp"


int main() {
    WeightedDirectedGraph<int> graph(6);

    // 构建示例有向带权图
    graph.insertEdge(0, {1, 2});
    graph.insertEdge(0, {2, 4});
    graph.insertEdge(1, {3, 1});
    graph.insertEdge(2, {3, 3});
    graph.insertEdge(2, {4, 5});
    graph.insertEdge(3, {5, 2});
    graph.insertEdge(4, {5, 1});

    // 进行拓扑排序
    std::vector<int> sortedVertices = topologicalSort(graph);

    // 输出拓扑排序结果
    std::cout << "Topological Sort Order: ";
    for (int vertex : sortedVertices) {
        std::cout << vertex << " ";
    }
    std::cout << std::endl;

    return 0;
}