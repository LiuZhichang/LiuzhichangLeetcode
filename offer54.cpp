#include <iostream>
#include <queue>
#include "Tree.h"
#include <vector>
void midOrder(TreeNode* root, std::vector<int>& vec) {
    if(root == nullptr)
        return;
    midOrder(root->left, vec);
    vec.push_back(root->val);
    midOrder(root->right, vec);
}

int kthLargest(TreeNode* root, int k) {
    std::vector<int> vec;
    midOrder(root, vec);
    return vec[k - 1];
}



int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->left = nullptr;
    root->left->right = new TreeNode(2);
    root->right->left = nullptr;
    root->right->right = nullptr;

    std::cout << kthLargest(root, 1) << std::endl;
    return 0;
}
