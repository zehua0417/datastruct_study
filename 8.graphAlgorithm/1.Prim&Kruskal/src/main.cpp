#include"../include/header.h"
#include"../include/edge.hpp"
#include"../include/graph.hpp"
#include"../include/weightedGraph.hpp"
//#include"../include/tree.hpp"
#include"../include/prim&kruskal.hpp"

/**
 * @attention 使用gravizo绘图, 想要可视化需要typora支持, 且需要科学上网
 */
void test(WeightedGraph<int>& graph){
    std::ofstream outputFile("D:\\vscode\\Project\\data_struct\\study\\8.graphAlgorithm\\1.Prim&Kruskal\\result.md");

    if (outputFile.is_open()) {  // 检查文件是否成功打开
        outputFile << "原图：\n";
        outputFile << "![graph](https://g.gravizo.com/g?" << std::endl;
        graph.outputGraphviz(outputFile);
        outputFile << "})" << std::endl;
        outputFile << "最小生成树：\n";
        outputFile << "\n---\n";
        outputFile << "### Prim算法\n";
        outputFile << "![graph](https://g.gravizo.com/g?" << std::endl;
        primAlgorithm(graph).outputGraphviz(outputFile);
        outputFile << "})" << std::endl;
        outputFile << "\n---\n";
        outputFile << "### Kruskal算法\n";
        outputFile << "![graph](https://g.gravizo.com/g?" << std::endl;
        kruskalAlgorithm(graph).outputGraphviz(outputFile);
        outputFile << "})" << std::endl;
        outputFile.close();  // 关闭文件流

        outputFile.close();
        std::cout << "success" << std::endl;
    } else {
        std::cout << "无法打开文件。\n";
    }
}


int main(){
    WeightedGraph<int> graph(5);

    graph.insertEdge(0, {1, 2});
    graph.insertEdge(0, {3, 6});
    graph.insertEdge(1, {2, 3});
    graph.insertEdge(1, {3, 8});
    graph.insertEdge(1, {4, 5});
    graph.insertEdge(2, {4, 7});
    graph.insertEdge(3, {4, 9});
    //testPrim(graph);
    test(graph);
    return 0;
}