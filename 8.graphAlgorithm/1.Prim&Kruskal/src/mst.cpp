#include"../include/algorithm.hpp"

int main(){

    ::Graph graph(6);
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 1);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(2, 4, 5);
    graph.addEdge(2, 5, 3);
    //graph.depthFirstPrint(0);
    //graph.breadthFirstPrint(0);
    printMST(graph,graph.primMST());

    std::cout << "kruskal algorithm" << std::endl;
    Tree<int>* mst = new Tree<int>();
    mst = kruskal_algorithm<int>(graph);
    mst->printTree();

    return 0;
}