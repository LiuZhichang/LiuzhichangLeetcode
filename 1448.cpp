#include <iostream>
#include "Tree.h"

int res;
void dfs(TreeNode* root, int max) {
    if(!root)
        return;
    if(root->val >= max) {
        ++ res;
        max = root->val;
    }
    dfs(root->left, max);
    dfs(root->right, max);
}
int goodNodes(TreeNode* root) {
    res = 0;
    dfs(root, root->val);
    return res;
}

int main(int argc, char* argv[]) {



    return 0;
}
