#include <functional>
#include <iostream>
#include "Tree.h"
#include <cmath>
#include <algorithm>
vector<int> pathInZigZagTree(int label) {
    int level = static_cast<int>(std::log(label) / std::log(2)) + 1;
    vector<int> res;
    res.push_back(label);
    while(level != 1) {
        int left = std::pow(2, level - 1);
        int right = std::pow(2, level) - 1;
        int parent = (left + right - label) / 2 ;
        res.push_back(parent);
        label = parent;
        -- level;
    }
    std::reverse(res.begin(), res.end());
    return res;
}
int main(int argc, char* argv[]) {
    //			  1
    //      3		   2
    //	 4     5     6    7
    // 15 14 13 12 11 10 9 8
    //
    // 1 3 2 4 5 6 7 15 14 13 12 11 10 9 8
    auto res = pathInZigZagTree(14);
    for(auto item : res) {
        std::cout << item << std::endl;
    }
    return 0;
}
