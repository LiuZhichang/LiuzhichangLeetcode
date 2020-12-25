#include <iostream>
#include "Tree.h"

int target_level;
int target_val;
TreeNode* dfs(TreeNode* node, int dep) {
    if(!node)
        return nullptr;
    if(dep == target_level) {
        TreeNode* newNode = new TreeNode(target_val);
        if(node->left)
            newNode->left = node->left;
        if(node->right)
            newNode->right = node->right;
        return newNode;
    }
    node->left = dfs(node->left, dep + 1);
    node->right = dfs(node->right, dep + 1);
    return node;
}
TreeNode* addOneRow(TreeNode* root, int v, int d) {
    if(!root) return nullptr;
    target_level = d;
    target_val = v;
    dfs(root, 1);
    return root;
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {4, 2, nullptr, 3, 1});
    TreeNode* root = addOneRow(t.getRoot(), 1, 3);
    t.Print();
    return 0;
}
