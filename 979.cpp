#include <iostream>
#include "Tree.h"

int res ;

int allocate(TreeNode* root) {
    if(!root)
        return 0;
    int left = allocate(root->left);
    int right = allocate(root->right);
    res += std::abs(left) + std::abs(right);
    //  if(root->val > 1) {
    //      int rv = root->val - 1;
    //      root->val = 1;
    //      return rv;
    //  }
    //  if(root->val == 0) {
    //      root->val = 1;
    //      return -1;
    //  }
    return root->val + left + right - 1;
}

void dfs(TreeNode* root) {
    if(!root)
        return;
    std::cout << root->val << std::endl;
    dfs(root->left);
    dfs(root->right);
}
int main(int argc, char* argv[]) {
    res = 0;
    Tree t(vector<Data> {0, 3, 0});
    allocate(t.getRoot());
    dfs(t.getRoot());
    std::cout << "res: " << res << std::endl;
    return 0;
}
