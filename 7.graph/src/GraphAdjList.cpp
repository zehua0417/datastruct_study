#include "../include/GraphAdjList.h"
#include <iostream>
#include <queue>

GraphAdjList::GraphAdjList(int num_vertices) : num_vertices(num_vertices) {
    adj_list.resize(num_vertices);
}

void GraphAdjList::addEdge(int src, int dest) {
    if (src >= 0 && src < num_vertices && dest >= 0 && dest < num_vertices) {
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
    }
}

void GraphAdjList::depthFirstTraversal(int start_vertex) {
    std::vector<bool> visited(num_vertices, false);
    _depthFirstTraversal(start_vertex, visited);
    std::cout << std::endl;
}

void GraphAdjList::_depthFirstTraversal(int vertex, std::vector<bool>& visited) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (int neighbor : adj_list[vertex]) {
        if (!visited[neighbor]) {
            _depthFirstTraversal(neighbor, visited);
        }
    }
}

void GraphAdjList::breadthFirstTraversal(int start_vertex) {
    std::vector<bool> visited(num_vertices, false);
    std::queue<int> queue;

    visited[start_vertex] = true;
    queue.push(start_vertex);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        std::cout << vertex << " ";

        for (int neighbor : adj_list[vertex]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                queue.push(neighbor);
            }
        }
    }

    std::cout << std::endl;
}
