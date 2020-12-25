#include <iostream>
#include "Tree.h"

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    TreeNode* root = new TreeNode(preorder[0]);

    return root;
}

int main(int argc, char* argv[]) {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};


    return 0;
}
