#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP
#include"../include/header.h"
#include"../include/graph.hpp"
#include"../include/weightedGraph.hpp"

template<typename T>
struct DijNode{
public:
    T id;
    T parent_id;
    int length;
    explicit DijNode(T id, T parent_id = NULL, int length = 0) : id(id), parent_id(parent_id), length(length){}

    bool operator <(const DijNode<T>& anotherNode)const {
        return this->length > anotherNode.length;
    }
    bool operator >(const DijNode<T>& anotherNode)const {
        return this->length < anotherNode.length;
    }
};

/**
 * @brief Dijkstra 算法
 * @tparam T 节点类型
 * @note 1. 每次从未标记的节点中选择距离出发点最近的节点, 标记, 收录到最优路径中
 * @note 2. 计算刚加入节点A的临近节点B的距离(不包含标记的节点), 若(节点A的距离+节点A到节点B的距离) < 节点B的距离, 则更新节点B的距离和前面的点
 */
template<typename T>
class Dijkstra{
public:
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    WeightedGraph<T> graph;
    std::vector<T> visited;
    std::vector<DijNode<T> > parent;
    std::priority_queue< DijNode<T> > pq;
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    explicit Dijkstra(WeightedGraph<T> graph) : graph(graph){};
    WeightedGraph<T> run(T begin, T end){
        parent.push_back(DijNode<T>(begin, NULL, 0));
        pq.push(DijNode<T>(begin, NULL, 0));
        T index = begin;

        while(visited.size() != graph.num_edges+1) {
            WEIGHT_ top_length = pq.top().length;
            visited.push_back(pq.top().id);
            pq.pop();
            for (auto& edge: graph.matrix[index]) {
                if(std::find(visited.begin(), visited.end(),edge.linked_vertex) != visited.end())
                    continue;
                pq.push(DijNode<T>(edge.linked_vertex, index, edge.weight + top_length));
            }
            auto now_top = pq.top();
            parent.push_back(DijNode<T>(now_top.id, now_top.parent_id, now_top.length));
            index = now_top.id;
        }

        WeightedGraph<T> shortestPath(graph.num_edges-2);

        for (auto node: parent) {
            shortestPath.insertEdge(0, {node.id, node.length});
        }
        return shortestPath;
    }
};

#endif // DIJKSTRA_HPP