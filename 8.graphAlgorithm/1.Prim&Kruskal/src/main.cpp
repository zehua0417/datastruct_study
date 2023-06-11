#include"../include/header.h"
#include"../include/edge.hpp"
#include"../include/graph.hpp"
#include"../include/weightedGraph.hpp"
#include"../include/tree.hpp"
#include"../include/prim&cruskal.hpp"

int main(){

    WeightedGraph<int>graph(5);
    graph.insertEdge(0, { 3, 3 });
    graph.insertEdge(0, { 1, 3 });
    graph.insertEdge(0, { 4, 9 });
    graph.insertEdge(1, { 2, 2 });
    graph.insertEdge(1, { 3, 4 });
    graph.insertEdge(1, { 4, 8 });
    //graph.print();
    std::cout << "![graph](https://g.gravizo.com/g?" << std::endl;
    graph.outputGraphviz(std::cout );
    std::cout << "})" << std::endl;

    std::cout << "---" << std::endl;

    auto tree = prim(graph);
    std::cout << "```mermaid" << std::endl;
    tree.outputAsMermaid();
    std::cout << "```" << std::endl;


    std::cin.get();
    return 0;
}

