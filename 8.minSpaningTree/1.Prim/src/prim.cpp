#include"../include/header.h"
#include"../include/graph.hpp"

int main(){
    using std::make_pair;

    ::Graph graph(6);
    graph.addEdge(0, 1, 1);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 4, 1);
    graph.addEdge(2, 5, 1);
    graph.depthFirstPrint(0);
    graph.breadthFirstPrint(0);

    return 0;
}