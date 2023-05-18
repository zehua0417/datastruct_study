#include "../include/GraphMatrix.h"
#include <iostream>
#include <queue>

GraphMatrix::GraphMatrix(int num_vertices) : num_vertices(num_vertices) {
    adj_matrix.resize(num_vertices, std::vector<int>(num_vertices, 0));
}

void GraphMatrix::addEdge(int src, int dest) {
    if (src >= 0 && src < num_vertices && dest >= 0 && dest < num_vertices) {
        adj_matrix[src][dest] = 1;
        adj_matrix[dest][src] = 1;
    }
}

void GraphMatrix::depthFirstTraversal(int start_vertex) {
    std::vector<bool> visited(num_vertices, false);
    _depthFirstTraversal(start_vertex, visited);
    std::cout << std::endl;
}

void GraphMatrix::_depthFirstTraversal(int vertex, std::vector<bool>& visited) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (int i = 0; i < num_vertices; ++i) {
        if (adj_matrix[vertex][i] == 1 && !visited[i]) {
            _depthFirstTraversal(i, visited);
        }
    }
}

void GraphMatrix::breadthFirstTraversal(int start_vertex) {
    std::vector<bool> visited(num_vertices, false);
    std::queue<int> queue;

    visited[start_vertex] = true;
    queue.push(start_vertex);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";

        for (int i = 0; i < num_vertices; ++i) {
            if (adj_matrix[vertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue.push(i);
            }
        }
    }

    std::cout << std::endl;
}
