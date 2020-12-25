#include <iostream>
#include "Tree.h"

int res = 0;
void dfs(TreeNode* root, int count, int target) {
    if(!root)
        return;
    dfs(root->left, count + 1, target);
    ++ count;
    if(count == target)
        std::cout << root->val << std::endl;
    dfs(root->right, count + 1, target);
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {5, 3, 6, 2, 4, nullptr, nullptr, 1});
    dfs(t.getRoot(), 1, 2);
//    std::cout << res << std::endl;
    return 0;
}
