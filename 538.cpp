#include <iostream>
#include "Tree.h"
int sum = 0;
void dfs(TreeNode* root) {
    if(!root)
        return;
    dfs(root->right);
    sum += root->val;
    root->val = sum;
    dfs(root->left);
}
void d(TreeNode* root) {
    if(!root) return;
    std::cout << root->val << std::endl;
    d(root->left);
    d(root->right);
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {4, 1, 6, 0, 2, 5, 7, nullptr, nullptr, nullptr, 3, nullptr, nullptr, nullptr, 8});
    dfs(t.getRoot());
    return 0;
}
