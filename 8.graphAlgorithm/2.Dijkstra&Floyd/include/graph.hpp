#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include"../include/header.h"
#include"../include/weightedEdge.hpp"

/**
 * @brief 图迭代器抽象类
 * @tparam T
 */
template<typename T>
class GraphIterator{
public:
    virtual ~GraphIterator() = default;

    virtual T operator *() const = 0;
    virtual void operator ++() = 0;
    virtual bool operator ==(const GraphIterator<T>&) const = 0;
    virtual bool operator !=(const GraphIterator<T>&) const = 0;
    virtual GraphIterator<T>* begin() const = 0;
    virtual GraphIterator<T>* end() const = 0;

};

/**
 * @brief 图抽象类
 * @tparam T
 */
template<typename T>
class Graph{
public:
     virtual ~Graph() = default;

     //ADT方法
     virtual int numberVertices() const = 0;
     virtual int numberEdges() const = 0;
     virtual bool existEdge(int, int) const = 0;
     virtual void insertEdge(int, const WeightedEdge<T>&) = 0;
     virtual void eraseEdge(int, int) = 0;
     virtual int degree(int) const = 0;
     virtual int inDegree(int) const = 0;
     virtual int outDegree(int) const = 0;

     //其他方法
     virtual bool directed() const = 0;
     virtual bool weighted() const = 0;
     virtual GraphIterator<T>* iterator(int) const = 0;
};

#endif