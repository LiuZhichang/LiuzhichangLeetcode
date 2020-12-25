#include <iostream>
#include "Tree.h"

void preorderTraversal(TreeNode* root, vector<TreeNode*> &l);

void flatten(TreeNode* root) {
    vector<TreeNode*> l;
    preorderTraversal(root, l);
    int n = l.size();
    for (int i = 1; i < n; i++) {
        TreeNode *prev = l.at(i - 1), *curr = l.at(i);
        prev->left = nullptr;
        prev->right = curr;
    }
}

void preorderTraversal(TreeNode* root, vector<TreeNode*> &l) {
    if (root != NULL) {
        l.push_back(root);
        preorderTraversal(root->left, l);
        preorderTraversal(root->right, l);
    }
}

void flatter2(TreeNode* root) {
    while(root) {
        if(!root->left)
            root = root->right;
        else {
            TreeNode* pre = root->left;
            while(pre->right)
                pre = pre->right;
            pre->right = root->right;
            root->right = root->left;
            root->left = nullptr;
            root = root->right;
        }
    }
}
TreeNode* pre = nullptr;

void flatten3(TreeNode* root) {
    if (root == nullptr)
        return;
    flatten(root->right);
    flatten(root->left);
    root->right = pre;
    root->left = nullptr;
    pre = root;
}

int main(int argc, char* argv[]) {
    Tree t(vector<Data> {1, 2, 5, 3, 4, nullptr, 6});
    flatten(t.getRoot());
    return 0;
}
