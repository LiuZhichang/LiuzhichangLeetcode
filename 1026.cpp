#include <cstdint>
#include <iostream>
#include "Tree.h"

int res = 0;
void dfs(TreeNode* root, int max, int min) {
    if(!root)
        return;
    if(root->val > max)
        max = root->val;
    if(root->val < min)
        min = root->val;
    res = std::max(res, std::max(std::abs(root->val - max), std::abs(root->val - min)))	;
    dfs(root->left, max, min);
    dfs(root->right, max, min);
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {8, 3, 10, 1, 6, nullptr, 14, nullptr, nullptr, 4, 7, 13});
    dfs(t.getRoot(), INT32_MIN, INT32_MAX);
    std::cout << res << std::endl;
    return 0;
}
