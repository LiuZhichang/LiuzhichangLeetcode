#include <iostream>
#include "Tree.h"

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if (root == nullptr || p == nullptr) return nullptr;
    if (p->val >= root->val) {
        return inorderSuccessor(root->right, p);
    } else {
        TreeNode* left = inorderSuccessor(root->left, p);
        return left ? left : root;
    }
}

TreeNode* inorderSuccessor_repeat(TreeNode* root, TreeNode* p) {
    if (p->right) {
        p = p->right;
        while (p->left) p = p->left;
        return p;
    }
    TreeNode* res = nullptr;
    while (root != p) {
        if (root->val < p->val) {
            root = root->right;
        } else {
            res = root;
            root = root->left;
        }
    }
    return res;
}

int main(int argc, char* argv[]) {

    // Tree t(vector<Data> {5, 3, 6, 2, 4, nullptr, nullptr, 1});
    Tree t(vector<Data> {2, 1, 3});
    t.Print();
    TreeNode* res = inorderSuccessor(t.getRoot(), new TreeNode(1));
    if(res)
        std::cout << res->val << std::endl;
    else
        std::cout << "null" << std::endl;
    return 0;
}
