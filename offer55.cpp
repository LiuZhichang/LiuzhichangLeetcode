#include <iostream>
#include "Tree.h"
#include <stack>
using std::stack;
int dfs(TreeNode* root, bool& flag) {
    if(root) {
        int left = dfs(root->left, flag);
        int right = dfs(root->right, flag);
        if(left - right > 1 || left - right < -1) {
            flag = false;
        }
        return left > right ? left + 1 : right + 1;
    }
    return 0;
}

void level(TreeNode* root) {
}

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    level(root);
    return 0;
}
