#ifndef FLOYD_HPP_
#define FLOYD_HPP_
#include"../include/header.h"
#include"../include/weightedEdge.hpp"
#include"../include/graph.hpp"
#include"../include/weightedGraph.hpp"
#include"../include/weightedDirectedGraph.hpp"

template<typename T>
void run(int count, int i, int j, WeightedDirectedGraph<T>& result);

template<typename T>
WeightedDirectedGraph<T> floyd(WeightedDirectedGraph<T>& graph){
    WeightedDirectedGraph<T> result(graph.num_vertices);

    //init
    for(int i = 0; i < graph.num_vertices; ++i){
       for(int j = 0; j < graph.num_vertices; ++j){
           if(i == j){
               result.insertEdge(i,{j,0});
               continue;
           }
           WEIGHT_ weight = graph.searchLinkedVertex(i,j);
           if(weight != -1){
               result.insertEdge(i,{j,weight});
           }else{
               result.insertEdge(i,{j,999});
           }
       }
    }

    //floyd
    for(int count = 0; count < graph.num_vertices; ++count){ //第i个十字
        for(int i = 0; i < graph.num_vertices; ++i){
            if(i == count) continue;
            for(int j = 0; j < graph.num_vertices; ++j){
                if(j==count) continue;
                //妈呀, 三层嵌套, 受不了了, 还是把函数放在外面吧
                run(count, i, j, result);
            }
        }
    }

    return result;
}

template<typename T>
void run(int count, int i, int j, WeightedDirectedGraph<T>& result){
    WEIGHT_ count_x = result.searchLinkedVertex(count, j);
    WEIGHT_ count_y = result.searchLinkedVertex(i,count);
    WEIGHT_ count_xy = count_x + count_y;
    if(count_xy < result.searchLinkedVertex(i,j)){
        result.changeEdgeWeight(i,j,count_xy);
    }
}

#endif