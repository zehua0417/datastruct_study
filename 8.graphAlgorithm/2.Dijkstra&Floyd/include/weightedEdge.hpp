#ifndef WEIGHTED_EDGE_HPP_
#define WEIGHTED_EDGE_HPP_

template<typename T>
class WeightedEdge{
public:
    T linked_vertex;
    WEIGHT_ weight;

    bool operator<(WeightedEdge<T>& anotherEdge){
        return this->weight < anotherEdge.weight;
    }
    bool operator>(WeightedEdge<T>& anotherEdge){
        return this->weight > anotherEdge.weight;
    }
    bool operator==(WeightedEdge<T>& anotherEdge){
        return this->weight == anotherEdge.weight;
    }

    WeightedEdge() : linked_vertex(-1), weight(-1) {}
    WeightedEdge(T linked_vertex, WEIGHT_ weight) : linked_vertex(linked_vertex), weight(weight) {}
};

#endif