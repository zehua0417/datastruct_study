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
public:
    explicit Graph(INDEX_ num_vertices); //构造函数

    int getNumVertices()const; //获取顶点数
    const std::vector<int> getLinked(INDEX_ src) const; //搜索相连的点
    bool ifLinked(INDEX_ src, INDEX_ dest); //判断两点是否相连
    WEIGHT_ getWeight(INDEX_ src, INDEX_ dest)const; //查找路径权值
    void depthFirstPrint(int start_vertex); //深度遍历打印
    void breadthFirstPrint(int start_vertex); // 广度优先遍历
    void addEdge(INDEX_ src, INDEX_ dest, WEIGHT_ weight); //添加边

    std::vector<std::pair<INDEX_, WEIGHT_>> primMST(); //Prim算法
};

#endif