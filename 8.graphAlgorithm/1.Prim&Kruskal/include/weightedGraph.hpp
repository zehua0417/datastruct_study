#ifndef WEIGHTED_GRAPH_HPP_
#define WEIGHTED_GRAPH_HPP_

#include "../include/header.h"
#include "../include/edge.hpp"
#include "../include/graph.hpp"

template<typename T>
class WeightedGraphIterator; // Incomplete declaration

/**
 * @brief 无向带权图
 * @tparam T
 */
template<typename T>
class WeightedGraph : public Graph<T> {
private:
    int num_vertices;
    int num_edges;

public:
    std::vector<std::list<Edge<T>>> matrix;
    explicit WeightedGraph(int size) : num_vertices(size), num_edges(0) {
        matrix.resize(num_vertices);
    }

    int numberVertices() const override {
        return num_vertices;
    }

    int numberEdges() const override {
        return num_edges;
    }

    bool existEdge(int u, int v) const override {
        for (const auto& edge : matrix[u]) {
            if (edge.linked_vertex == v)
                return true;
        }
        return false;
    }

    void insertEdge(int vertice, const Edge<T>& edge) override {
        if (existEdge(vertice, edge.linked_vertex)) {
            std::cout << "ERROR: " << std::endl;
            std::cout << vertice << " & " << edge.linked_vertex << " is already linked" << std::endl;
            return;
        }
        matrix[vertice].push_back(edge);
        matrix[edge.linked_vertex].push_back({ vertice, edge.weight });
        num_edges++;
    }

    void insertEdge(std::pair<int, Edge<T>&> edge) {
        insertEdge(edge.first, edge.second);
    }


    void eraseEdge(int u, int v) override {
        if (!existEdge(u, v)) {
            std::cout << "ERROR: " << std::endl;
            std::cout << u << " & " << v << " is not linked yet" << std::endl;
            return;
        }
        for (auto it = matrix[u].begin(); it != matrix[u].end(); ++it) {
            if (it->linked_vertex == v) {
                matrix[u].erase(it);
                break;
            }
        }
        for (auto it = matrix[v].begin(); it != matrix[v].end(); ++it) {
            if (it->linked_vertex == u) {
                matrix[v].erase(it);
                break;
            }
        }
        num_edges--;
    }

    int degree(int v) const override {
        return matrix[v].size();
    }

    int inDegree(int v) const override {
        int inDegree = 0;
        for (const auto& edges : matrix) {
            for (const auto& edge : edges) {
                if (edge.linked_vertex == v) {
                    inDegree++;
                }
            }
        }
        return inDegree;
    }

    int outDegree(int v) const override {
        return degree(v);
    }

    bool directed() const override {
        return false;
    }

    bool weighted() const override {
        return true;
    }

    GraphIterator<T>* iterator(int v) const override;

    void print(){
        for(int i = 0; i < num_vertices; ++i){
            std::cout << i << ": ";
            for(const auto& edge : matrix[i]){
                std::cout << edge.linked_vertex << "(" << edge.weight << ") ";
            }
            std::cout << std::endl;
        }
    }

    void outputGraphviz(std::ostream& out) const {
        out << "graph G {\n";

        for (int i = 0; i < num_vertices; ++i) {
            out << "  " << i << ";\n";
        }

        for (int i = 0; i < num_vertices; ++i) {
            for (const auto& edge : matrix[i]) {
                if (i < edge.linked_vertex) {  // 只输出一次边
                    out << "  " << i << " -- " << edge.linked_vertex << " [label=\"" << edge.weight << "\"];\n";
                }
            }
        }

    }


};

/**
 * @brief 无向带权图的迭代器
 * @tparam T
 */
template<typename T>
class WeightedGraphIterator : public GraphIterator<T> {
private:
    const WeightedGraph<T>& w_graph;
    int currentVertex;  // 当前顶点的索引
    typename std::list<Edge<T>>::const_iterator currentEdgeIterator;  // 当前顶点邻接表中的边迭代器

public:
    WeightedGraphIterator(const WeightedGraph<T>& graph, int v)
            : w_graph(graph), currentVertex(v), currentEdgeIterator(w_graph.matrix[v].begin()) {}

    T operator*() const override {
        return currentEdgeIterator->linked_vertex;
    }

    void operator++() override {
        ++currentEdgeIterator;
        if (currentEdgeIterator == w_graph.matrix[currentVertex].end()) {
            ++currentVertex;
            if (currentVertex < w_graph.numberVertices())
                currentEdgeIterator = w_graph.matrix[currentVertex].begin();
        }
    }

    bool operator==(const GraphIterator<T>& other) const override {
        const auto* derived = dynamic_cast<const WeightedGraphIterator<T>*>(&other);
        if (derived == nullptr)
            return false;
        return (currentVertex == derived->currentVertex) && (currentEdgeIterator == derived->currentEdgeIterator);
    }

    bool operator!=(const GraphIterator<T>& other) const override {
        return *this != other;
    }

    GraphIterator<T>* begin() const override {
        return new WeightedGraphIterator<T>(w_graph, 0);
    }

    // 无向图的迭代器的end()方法返回的是一个指向最后一个顶点的下一个顶点的迭代器
    GraphIterator<T>* end() const override {
        return new WeightedGraphIterator<T>(w_graph, w_graph.numberVertices());
    }



};

template<typename T>
GraphIterator<T>* WeightedGraph<T>::iterator(int v) const {
    return new WeightedGraphIterator<T>(*this, v);
}

#endif // WEIGHTED_GRAPH_HPP_
