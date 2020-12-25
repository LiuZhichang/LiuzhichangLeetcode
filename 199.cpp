#include <iostream>
#include "Tree.h"
vector<int> res;
vector<int> rightSideView(TreeNode* root) {
    if(!root)
        return res;
    res.push_back(root->val);
    rightSideView(root->right);
    return res;
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {1, 2, 3, nullptr, 5, nullptr, 4});

    rightSideView(t.getRoot());


    return 0;
}
