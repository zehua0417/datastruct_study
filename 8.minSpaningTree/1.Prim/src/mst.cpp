#include"../include/header.h"
#include"../include/graph.h"
#include"../include/algorithm.h"

int main(){
    using std::make_pair;

    ::Graph graph(6);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 5);
    graph.addEdge(2, 5, 3);
    graph.depthFirstPrint(0);
    graph.breadthFirstPrint(0);
    printMST(graph,graph.primMST());

    return 0;
}