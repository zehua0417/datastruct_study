#ifndef UNION_FIND_H_
#define UNION_FIND_H_
#include"../include/header.h"

class UnionFind {
private:
    std::vector<int> parent;
    std::vector<int> rank;
public:
    UnionFind(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        return parent[i];
    }

    void unionSet(int i, int j) {
        int ri = find(i), rj = find(j);
        if(ri != rj) {
            if(rank[ri] < rank[rj])
                parent[ri] = rj;
            else if(rank[ri] > rank[rj])
                parent[rj] = ri;
            else {
                parent[ri] = rj;
                rank[rj]++;
            }
        }
    }
};


#endif