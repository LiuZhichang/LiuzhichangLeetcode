#include <iostream>
#include "Tree.h"

int target = 2;

void dfs(TreeNode* root, TreeNode* parent) {
    if(root == nullptr)
        return;
    dfs(root->left, root);
    dfs(root->right, root);
    if(root->left == nullptr && root->right == nullptr)
        if(root->val == target) {
            std::cout << "child " << root->val << std::endl;
            if(parent->val == target && parent->left == nullptr && parent->right == nullptr)
                std::cout << parent->val << std::endl;
        }
}

void d(TreeNode* root) {
    if(root == nullptr)
        return;
    std::cout << root->val << std::endl;
    d(root->left);
    d(root->right);
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {1, 2, 3, 2, nullptr, 2, 4});
    dfs(t.getRoot(), nullptr);
    // d(t.getRoot());
    return 0;
}
