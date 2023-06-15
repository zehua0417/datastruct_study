#ifndef WEIGHTED_DIRECTED_GRAPH_HPP_
#define WEIGHTED_DIRECTED_GRAPH_HPP_
#include"../include/header.h"
#include"../include/weightedEdge.hpp"
#include"../include/graph.hpp"
#include"../include/weightedGraph.hpp"
//////////////////////////////////////
// 实在不好意思,组合就是垃圾,继承才是最屌的 //
//////////////////////////////////////
/**
 * @brief 有向带权图
 * @tparam T
 */
template<typename T>
class WeightedDirectedGraph : public WeightedGraph<T> {
public:
    WeightedDirectedGraph(int num) : WeightedGraph<T>(num) {}
    //更改无向图的insert, 为单边插入
    void insertEdge(int vertice, const WeightedEdge<T>& edge) override{
        if(WeightedGraph<T>::existEdge(vertice, edge.linked_vertex)){
            std::cout << "ERROR: " << std::endl;
            std::cout << vertice << " & " << edge.linked_vertex << " is already linked" << std::endl;
            return;
        }
        WeightedGraph<T>::matrix[vertice].push_back(edge);
        WeightedGraph<T>::num_edges++;
    }


    void outputGraphviz(std::ostream& out) const {
        out << "digraph G {\n";

        for (int i = 0; i < WeightedGraph<T>::num_vertices; ++i) {
            out << "  " << i << ";\n";
        }

        for(int i = 0; i < WeightedGraph<T>::num_vertices; ++i){
            for(const auto& edge : WeightedGraph<T>::matrix[i]){
                out << i << " -> " << edge.linked_vertex << " [label = \"" << edge.weight << "\"];\n";
            }
        }
    }

    void input(){
        for(int i = 0; i < WeightedGraph<T>::num_vertices; ++i) {
            std::cout << "\t[" << i << ", ]";
        }
        std::cout << std::endl;
        for(int i = 0; i < WeightedGraph<T>::num_vertices; ++i){
            std::cout << "[ ," << i << "]\t";
            for(int j = 0; j < WeightedGraph<T>::num_vertices; ++j){
                int temp;
                std::cin >> temp;
                insertEdge(i,{j,temp});
            }
        }
    }

    void changeEdgeWeight(int x, int y, WEIGHT_ weight){
        for(auto &edge : WeightedGraph<T>::matrix[x]){
            if(edge.linked_vertex == y){
                edge.weight = weight;
                break;
            }
        }
    }
};

#endif