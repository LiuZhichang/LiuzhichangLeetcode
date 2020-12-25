#include <iostream>
#include "Tree.h"

TreeNode* pruneTree(TreeNode* root) {

    if(!root)
        return nullptr;
    root->left = pruneTree(root->left);
    root->right = pruneTree(root->right);
    if(root->left == nullptr && root->right == nullptr && root->val == 0) {
        return nullptr;
    }
    return root;
}

void dfs(TreeNode* root) {
    if(!root)
        return;
    std::cout << root->val << std::endl;
    dfs(root->left);
    dfs(root->right);
}

int main(int argc, char* argv[]) {
    Tree t(vector<Data> {1, 0, 1, 0, 0, 0, 1});
    TreeNode* root = pruneTree(t.getRoot());
    t.Print();
    // dfs(root);
    return 0;
}
