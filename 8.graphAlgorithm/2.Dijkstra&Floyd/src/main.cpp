#include"../include/header.h"
#include"../include/Dijkstra.hpp"
#include"../include/floyd.hpp"

int main(){
    WeightedGraph<int>graph(6);
    graph.insertEdge(0,{1,5});
    graph.insertEdge(0,{2,1});
    graph.insertEdge(1,{2,2});
    graph.insertEdge(1,{3,1});
    graph.insertEdge(2,{3,4});
    graph.insertEdge(2,{4,8});
    graph.insertEdge(3,{4,3});
    graph.insertEdge(3,{5,6});

    std::ofstream outputFile("D:\\vscode\\Project\\data_struct\\study\\8.graphAlgorithm\\2.Dijkstra&Floyd\\result.md");

    outputFile << "### 原图：\n";
    outputFile << "![graph](https://g.gravizo.com/g?" << std::endl;
    graph.outputGraphviz(outputFile);
    outputFile << "})\n" << std::endl;

    outputFile << "---" << std::endl;
    outputFile << "### Dijkstra算法：\n";

    Dijkstra<int>dij_al(graph);
    WeightedGraph<int>result =  dij_al.run(0,6);
    outputFile  << "![graph](https://g.gravizo.com/g?" << std::endl;
    result.outputGraphviz(outputFile);
    outputFile << "})\n" << std::endl;

    outputFile << "---" << std::endl;
    ::WeightedDirectedGraph<int> graph2(4);
    /*
     *      0   1   2   3
     *  0   0   1   ❌  4
     *  1   ❌  0   4   2
     *  2   3   5   0   8
     *  3   ❌ ❌  6   0
     */
    graph2.insertEdge(0,{2,3});
    graph2.insertEdge(1,{0,1});
    graph2.insertEdge(1,{2,5});
    graph2.insertEdge(2,{1,4});
    graph2.insertEdge(2,{3,6});
    graph2.insertEdge(3,{0,4});
    graph2.insertEdge(3,{1,2});
    graph2.insertEdge(3,{2,8});
    //graph2.input();
    outputFile << "原图:\n";
    outputFile << "![WeightedDirectedGraph](https://g.gravizo.com/g?" << std::endl;
    graph2.outputGraphviz(outputFile);
    outputFile << "})\n" << std::endl;

    outputFile << "---" << std::endl;
    outputFile << "### Floyd算法: \n";
    WeightedDirectedGraph<int> result2 = floyd(graph2);
    outputFile << "![WeightedDirectedGraph](https://g.gravizo.com/g?" << std::endl;
    result2.outputGraphviz(outputFile);
    outputFile << "})\n" << std::endl;



    std::cin.get();
    return 0;
}