#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include"../include/header.h"

/*
 * @brief 邻接表表示的图
 */
class Graph{
private:
    int num_vertices; // 顶点边
    std::vector<std::list<std::pair<INDEX_, WEIGHT_> > > adj_list; //邻接表
    template<typename Func>
    void _depthFirstForeach(int vertex, std::vector<bool>& visited, Func func);//深度遍历
    template<typename Func>
    void _breadthFirstForeach(int start_vertex, Func func);//广度遍历
    // Kruskal辅助函数：查找根节点
    INDEX_ find(std::vector<INDEX_>& parent, INDEX_ vertex);

    // kruskal辅助函数：合并两个连通分量
    void unionSets(std::vector<INDEX_>& parent, INDEX_ root1, INDEX_ root2);
    std::vector<std::pair<INDEX_, INDEX_>> kruskalMST();
public:
    explicit Graph(INDEX_ num_vertices); //构造函数

    std::vector<INDEX_> getLinked(INDEX_ src); //搜索相连的点
    bool ifLinked(INDEX_ src, INDEX_ dest); //判断两点是否相连
    WEIGHT_ getWeight(INDEX_ src, INDEX_ dest)const; //查找路径权值
    void depthFirstPrint(int start_vertex); //深度遍历打印
    void breadthFirstPrint(int start_vertex); // 广度优先遍历
    void addEdge(INDEX_ src, INDEX_ dest, WEIGHT_ weight); //添加边


    std::vector<std::pair<INDEX_, WEIGHT_>> primMST();
};

#endif