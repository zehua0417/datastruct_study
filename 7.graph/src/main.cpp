#include "../include/GraphMatrix.h"
#include "../include/GraphAdjList.h"
#include <iostream>

int main() {
    // 使用邻接矩阵表示图的测试
    GraphMatrix graph_matrix(6);
    graph_matrix.addEdge(0, 1);
    graph_matrix.addEdge(0, 2);
    graph_matrix.addEdge(1, 3);
    graph_matrix.addEdge(2, 4);
    graph_matrix.addEdge(2, 5);

    std::cout << "Depth First Traversal (Matrix): ";
    graph_matrix.depthFirstTraversal(0);

    std::cout << "Breadth First Traversal (Matrix): ";
    graph_matrix.breadthFirstTraversal(0);

    // 使用邻接表表示图的测试
    GraphAdjList graph_adj_list(6);
    graph_adj_list.addEdge(0, 1);
    graph_adj_list.addEdge(0, 2);
    graph_adj_list.addEdge(1, 3);
    graph_adj_list.addEdge(2, 4);
    graph_adj_list.addEdge(2, 5);

    std::cout << "Depth First Traversal (Adjacency List): ";
    graph_adj_list.depthFirstTraversal(0);

    std::cout << "Breadth First Traversal (Adjacency List): ";
    graph_adj_list.breadthFirstTraversal(0);

    return 0;
}
