/*================================================================
*   Copyright (C) 2020 Sangfor Ltd. All rights reserved.
*
*   文件名称：1343.cpp
*   创 建 者：Liu zhichang
*   创建日期：2020年07月29日
*   描    述：大小为k且平均值大于等于阈值的子数组数目
*
================================================================*/


// #include "1343.h"
#include <iostream>
#include <vector>

int numOfSubarrays(std::vector<int>& arry, int k, int threshold) {
    if(arry.empty())
        return 0;
    int res = 0;
    std::vector<int> sum(arry.size() + 1, 0);
    int target = k * threshold;

    for(int i = 0 ; i < arry.size() ; i++) {
        sum[i + 1] = sum[i] + arry[i];
    }
    for(int i = k; i < sum.size(); i++) {
        if(sum[i] - sum[i - k] >= target) {
            res ++;
        }
    }
    return res;
}

int main(int argc, char *argv[]) {
    std::vector<int> v{7, 7, 7, 7, 7};

    std::cout << numOfSubarrays(v, 5, 7) << std::endl;

    return 0;
}
