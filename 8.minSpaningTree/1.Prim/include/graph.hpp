#ifndef GRAPH_HPP_
#define GRAPH_HPP_
#include"../include/header.h"

#define INDEX_ int
#define WEIGHT_ int

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
    explicit Graph(int num_vertices); //构造函数
    void depthFirstPrint(int start_vertex); //深度遍历打印
    void breadthFirstPrint(int start_vertex); // 广度优先遍历
    void addEdge(INDEX_ src, INDEX_ dest, WEIGHT_ weight); //添加边
};

Graph::Graph(INDEX_ num_vertices) : num_vertices(num_vertices){
    adj_list.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        adj_list[i] = std::list<std::pair<INDEX_, WEIGHT_> >(); // 将每个列表初始化为空
    }
}

template<typename Func> //使用模板接受lamda表达式
void Graph::_depthFirstForeach(INDEX_ vertex, std::vector<bool> &visited, Func func) {
    visited[vertex] = true;
    func(vertex);
    for(const auto& neighbor : adj_list[vertex]) {
        if (!visited[neighbor.first]) {
            _depthFirstForeach(neighbor.first, visited, func);
        }
    }
}

template<typename Func> //使用模板接受lamda表达式
void Graph::_breadthFirstForeach(INDEX_ start_vertex, Func func) {
    std::vector<bool> visited(num_vertices, false);
    std::queue<int> queue;

    visited[start_vertex] = true;
    queue.push(start_vertex);

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        func(vertex);

        for (auto& neighbor : adj_list[vertex]) {
            if (!visited[neighbor.first]) {
                visited[neighbor.first] = true;
                queue.push(neighbor.first);
            }
        }
    }

    std::cout << std::endl;
}

void Graph::depthFirstPrint(INDEX_ start_vertex){
    std::vector<bool> visited(num_vertices, false);
    auto func = [this](INDEX_ vertex){
        for(auto& pair : this->adj_list[vertex]){
            std::cout << vertex << "-" << pair.first << ": " << pair.second <<"    ";
        }
    };
    _depthFirstForeach(start_vertex, visited, func);
    std::cout << std::endl;
}

void Graph::breadthFirstPrint(INDEX_ start_vertex) {
    _breadthFirstForeach(start_vertex, [this](int vertex){
        for(auto& pair : this->adj_list[vertex]){
            std::cout << vertex << "-" << pair.first << ": " << pair.second <<"    ";
        }
    });
    std::cout << std::endl;
}

void Graph::addEdge(INDEX_ src, INDEX_ dest, WEIGHT_ weight){
    if(src >= 0 && src < num_vertices && dest >= 0 && dest < num_vertices) {
        adj_list[src].emplace_back(std::make_pair(dest,weight));
        adj_list[dest].emplace_back(std::make_pair(src, weight));
    }
}

#endif