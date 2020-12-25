#include <iostream>
#include "Tree.h"

TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr)
        return nullptr;
    if (root->val < low)
        return trimBST(root->right, low, high);
    if (root->val > high)
        return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);

    return root;
}

int main(int argc, char* argv[]) {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(0);
    root->right = new TreeNode(4);

    root->left->right = new TreeNode(2);

    root->left->right->left = new TreeNode(1);

    trimBST(root, 1, 3);

    return 0;
}
