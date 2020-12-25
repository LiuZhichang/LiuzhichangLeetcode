#include <iostream>
#include "Tree.h"
bool isValidBST(TreeNode* root) {
    if(!root)
        return true;
    if(root->left) if(root->left->val >= root->val) return false;
    if(root->right) if(root->right->val <= root->val) return false;
    bool l = isValidBST(root->left);
    bool r = isValidBST(root->right);
    return l && r;
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {10, 5, 15, nullptr, nullptr, 6, 20});
    t.Print();

    return 0;
}
