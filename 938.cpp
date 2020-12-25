#include <iostream>
#include "Tree.h"

int res = 0;

void dfs(TreeNode* node, int L, int R) {
    if(node != nullptr) {
        if(node->val >= L && node->val <= R) {
            res += node->val;
        }
        if(node->val > L) {
            dfs(node->left, L, R);
        }
        if(node->val < R) {
            dfs(node->right, L, R);
        }
    }
}

int rangeSumBST(TreeNode * root, int L, int R) {
    dfs(root, L, R);
    return res;
}

int main(int argc, char* argv[]) {



    return 0;
}
