#include <iostream>
#include "Tree.h"
#include <map>
using std::map;
vector<int> findRedundanConnection(vector<vector<int>>& edges) {
    vector<int> res;
    if(edges.empty())
        return res;
    map<int, int> m;
    for(auto edge : edges) {
        ++m[edge[1]];
        if(m[edge[1]] > 1)
            res = edge;
    }

    return res;
}

int main(int argc, char* argv[]) {

    vector<vector<int>> edges{{1, 2}, {1, 3}, {2, 3}};
    auto res = findRedundanConnection(edges);

    for(auto item : res)
        std::cout << item << std::endl;

    return 0;
}
