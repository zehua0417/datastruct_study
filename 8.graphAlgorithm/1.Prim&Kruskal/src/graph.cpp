#include"../include/header.h"
#include"../include/graph.h"
Graph::Graph(INDEX_ num_vertices) : num_vertices(num_vertices){
    adj_list.resize(num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        adj_list[i] = std::list<std::pair<INDEX_, WEIGHT_> >(); // 将每个列表初始化为空
    }
}

int Graph::getNumVertices()const{
    return num_vertices;
}

const std::vector<INDEX_> Graph::getLinked(INDEX_ src) const {
    if(src >= 0 && src < num_vertices) {
        std::vector<INDEX_> points;
        for (const auto &pair: adj_list[src]) {
            points.push_back(pair.first);
        }
        return points;
    }
    return {};
}

bool Graph::ifLinked(INDEX_ src, INDEX_ dest){
    if(src >= 0 && src < num_vertices && dest >= 0 && dest < num_vertices) {
        for (const auto& pair : adj_list[src]) {
            if (pair.first == dest) {
                return true;
            }
        }
    }
    return false;
}

WEIGHT_ Graph::getWeight(INDEX_ src, INDEX_ dest)const{
    if(src >= 0 && src < num_vertices && dest >= 0 && dest < num_vertices) {
        for (const auto& pair : adj_list[src]){
            if(pair.first == dest){
                return pair.second;
            }
        }
    }
    return -1;
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

std::vector<std::pair<INDEX_, WEIGHT_>> Graph::primMST() {
    std::vector<bool> visited(num_vertices, false);  // 记录顶点是否被访问过
    std::vector<WEIGHT_> key(num_vertices, std::numeric_limits<WEIGHT_>::max());  // 记录顶点到MST的最小权值
    std::vector<INDEX_> parent(num_vertices, -1);  // 记录顶点在MST中的父节点
    std::vector<std::pair<INDEX_, WEIGHT_>> mst;  // 最小生成树

    // 从第一个顶点开始构建MST
    key[0] = 0;
    std::priority_queue<std::pair<WEIGHT_, INDEX_>, std::vector<std::pair<WEIGHT_, INDEX_>>, std::greater<>> pq;
    pq.push(std::make_pair(0, 0));

    while (!pq.empty()) {
        INDEX_ u = pq.top().second;
        pq.pop();

        visited[u] = true;

        // 遍历u的邻接顶点
        for (const auto& neighbor : adj_list[u]) {
            INDEX_ v = neighbor.first;
            WEIGHT_ weight = neighbor.second;

            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push(std::make_pair(weight, v));
            }
        }
    }

    // 构建最小生成树
    for (INDEX_ i = 1; i < num_vertices; i++) {
        mst.push_back(std::make_pair(parent[i], i));
    }

    return mst;
}