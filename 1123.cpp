#include <iostream>
#include "Tree.h"

TreeNode* ancestor = nullptr;
int max_depth = 0;

int dfs(TreeNode* node, int depth) {
    if (node == nullptr) {
        return depth - 1;
    }

    int left_depth = dfs(node->left, depth + 1);
    int right_depth = dfs(node->right, depth + 1);

    max_depth = std::max(max_depth, std::max(left_depth, right_depth)); //更新叶节点最大深度

    if (left_depth == max_depth && right_depth == max_depth) { //左、右子树都有最深叶节点
        ancestor = node;
    }

    return std::max(left_depth, right_depth);
}


int main(int argc, char* argv[]) {

    Tree t(vector<Data> {3, 5, 1, 6, 2, 0, 8, nullptr, nullptr, 7, 4});
    dfs(t.getRoot(), 0);
    return 0;
}
