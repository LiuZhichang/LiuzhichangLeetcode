#include <cstdint>
#include <iostream>
#include "Tree.h"


int maxDepth(TreeNode* root) {
    if(root != nullptr) {
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return left > right ? left + 1 : right + 1;
    }
    return 0;
}

int main(int argc, char* argv[]) {
    TreeNode root(0);
    std::cout << maxDepth(&root) << std::endl;

    return 0;
}
