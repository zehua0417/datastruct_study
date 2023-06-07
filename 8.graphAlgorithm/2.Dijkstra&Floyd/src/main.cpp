#include"../include/header.h"
#include"../include/graph.h"
#include"./algorithm.hpp"

int main(void){

    ::Graph graph(6);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 5);
    graph.addEdge(2, 5, 3);
    //graph.depthFirstPrint(0);
    //graph.breadthFirstPrint(0);
    dijkstra1(graph, 0);

    std::cout << "==========" << std::endl;

    auto result2 = floyd(graph);
    for(const auto& i : result2){
        for(const auto& j : i){
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    std::cin.get();
    return 0;
}