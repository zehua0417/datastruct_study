#include"../include/header.h"
#include"../include/graph.h"

/**
 * @brief dijkstra算法
 *
 * @param graph 图
 * @param start_vertex 起始点
 * @return string 样例: 0->2->5->3->1->4->6, 总长度: 13
 * @note 1. 每次从未标记的节点中选择距离出发点最近的节点, 收录到最优路径中
 *       2. 计算刚加入节点A的临近节点B的距离, 不包含标记的节点, 若节点A的距离加上A到B的距离小于节点B的距离, 则更新节点B的距离和前面点
 */
std::vector<std::pair<INDEX_, WEIGHT_> > dijkstra(const ::Graph& graph,INDEX_ start_vertex){
    std::vector<std::pair<INDEX_, WEIGHT_> > result;
    std::vector<WEIGHT_> dist(graph.getNumVertices(), INT_MAX); //初始化距离
    std::vector<bool> visited(graph.getNumVertices(), false); //初始化访问
    std::vector<INDEX_> parent(graph.getNumVertices(), -1); //初始化父节点
    dist[start_vertex] = 0; //起始点距离为0
    for(int i = 0; i < graph.getNumVertices(); i++){
        int min_dist = INT_MAX;
        int min_index = -1;
        for(int j = 0; j < graph.getNumVertices(); j++){
            if(!visited[j] && dist[j] < min_dist){
                min_dist = dist[j];
                min_index = j;
            }
        }
        if(min_index == -1){
            break;
        }
        visited[min_index] = true;
        for(const auto& neighbor : graph.getLinked(min_index)){
            if(!visited[neighbor] && dist[min_index] + graph.getWeight(min_index, neighbor) < dist[neighbor]){
                dist[neighbor] = dist[min_index] + graph.getWeight(min_index, neighbor);
                parent[neighbor] = min_index;
            }
        }
    }
    for(int i = 0; i < graph.getNumVertices(); i++){
        result.push_back(std::make_pair(i, dist[i]));
    }
    return result;
}
/**
 * @brief dijkstra算法
 *
 * @param graph 图
 * @param start_vertex 起始点
 * @return string 样例: 0->2->5->3->1->4->6, 总长度: 13
 * @note 1. 每次从未标记的节点中选择距离出发点最近的节点, 收录到最优路径中
 *       2. 计算刚加入节点A的临近节点B的距离, 不包含标记的节点, 若节点A的距离加上A到B的距离小于节点B的距离, 则更新节点B的距离和前面点
 */
std::string dijkstra1(const ::Graph& graph, INDEX_ start_vertex){
    std::string result;
    std::vector<WEIGHT_> dist(graph.getNumVertices(), INT_MAX); //初始化距离
    std::vector<bool> visited(graph.getNumVertices(), false); //初始化访问
    std::vector<INDEX_> parent(graph.getNumVertices(), -1); //初始化父节点
    dist[start_vertex] = 0; //起始点距离为0
    for(int i = 0; i < graph.getNumVertices(); i++){
        int min_dist = INT_MAX;
        int min_index = -1;
        for(int j = 0; j < graph.getNumVertices(); j++){
            if(!visited[j] && dist[j] < min_dist){
                min_dist = dist[j];
                min_index = j;
            }
        }
        if(min_index == -1){
            break;
        }
        visited[min_index] = true;
        for(const auto& neighbor : graph.getLinked(min_index)){
            if(!visited[neighbor] && dist[min_index] + graph.getWeight(min_index, neighbor) < dist[neighbor]){
                dist[neighbor] = dist[min_index] + graph.getWeight(min_index, neighbor);
                parent[neighbor] = min_index;
            }
        }
    }
    for(int i = 0; i < graph.getNumVertices(); i++){
        std::cout << i << " " << dist[i] << std::endl;
    }
    for(int i = 0; i < graph.getNumVertices(); i++){
        int index = i;
        while(index != start_vertex){
            result = "->" + std::to_string(index) + result;
            index = parent[index];
        }
        result = std::to_string(start_vertex) + result;
        std::cout << result << std::endl;
        result.clear();
    }
    return result;
}
/**
 * @brief floyd算法
 *
 * @param graph 图
 * @return std::vector<std::vector<WEIGHT_> >
 */
std::vector<std::vector<WEIGHT_> > floyd(::Graph graph) {
    std::vector<std::vector<WEIGHT_> > result(graph.getNumVertices(),
                                              std::vector<WEIGHT_>(graph.getNumVertices(), INT_MAX));
    for (int i = 0; i < graph.getNumVertices(); i++) {
        for (int j = 0; j < graph.getNumVertices(); j++) {
            if (i == j) {
                result[i][j] = 0;
            } else if (graph.ifLinked(i, j)) {
                result[i][j] = graph.getWeight(i, j);
            }
        }
    }
    for (int k = 0; k < graph.getNumVertices(); k++) {
        for (int i = 0; i < graph.getNumVertices(); i++) {
            for (int j = 0; j < graph.getNumVertices(); j++) {
                if (result[i][k] != INT_MAX && result[k][j] != INT_MAX && result[i][k] + result[k][j] < result[i][j]) {
                    result[i][j] = result[i][k] + result[k][j];
                }
            }
        }
    }
    return result;
}