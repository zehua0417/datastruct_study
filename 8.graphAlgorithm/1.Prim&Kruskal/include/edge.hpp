#ifndef EDGE_HPP_
#define EDGE_HPP_

template<typename T>
class Edge{
public:
    T linked_vertex;
    WEIGHT_ weight;

    bool operator<(Edge<T>& anotherEdge){
        return this->weight < anotherEdge.weight;
    }
    bool operator>(Edge<T>& anotherEdge){
        return this->weight > anotherEdge.weight;
    }
    bool operator==(Edge<T>& anotherEdge){
        return this->weight == anotherEdge.weight;
    }
};

#endif