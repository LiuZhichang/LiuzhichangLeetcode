#include "Tree.h"

class Solution {

  public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return repeat(root->left, root->right);
    }
    bool repeat(TreeNode* left, TreeNode* right) {
        if(left == nullptr && right == nullptr)
            return true;
        if(left == nullptr || right == nullptr || left->val != right->val)
            return false;
        return repeat(left->left, right->right) && repeat(left->right, right->left);
    }
};
