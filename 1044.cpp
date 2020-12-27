/*
 给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

 返回仅包含 1 的最长（连续）子数组的长度。

  

 示例 1：

 输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
 输出：6
 解释：
 [1,1,1,0,0,1,1,1,1,1,1]
 粗体数字从 0 翻转到 1，最长的子数组长度为 6。
*/


#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using std::vector;

int longestOnes(vector<int>& A, int K) {
    int count = 0;
    int left = 0, right = 0;
    int res = -1;;
    while(right < A.size()) {
        if(!A[right])
            ++count;
        // 收缩窗口
        while(count > K) {
            if(A[left] == 0)
                --count;
            ++left;
        }
        // 每次0的个数必定 <= K
        res = std::max(right - left + 1, res);
        ++right;
    }
    return res;
}

int main(int argc, char** argv) {

    vector<int> nums{0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};

    int res = longestOnes(nums, 3);
    std::cout << res << std::endl;

    return 0;
}
