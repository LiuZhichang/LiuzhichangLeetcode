#include <iostream>
#include "Tree.h"
class Solution {
    TreeNode* head;
    TreeNode* pre;
  public:
    void dfs(TreeNode* root) {
        if(!root)
            return;
        dfs(root->left);
        root->left = nullptr;
        pre->right = root;
        pre = root;
        dfs(root->right);
    }
    TreeNode* convertBiNode(TreeNode* root) {
        head = new TreeNode(-1);
        pre = head;
        dfs(root);
        return head->right;
    }
};

int main(int argc, char* argv[]) {



    return 0;
}
