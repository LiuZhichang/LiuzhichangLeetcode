#include <iostream>
#include "Tree.h"

int res = 0;
int maxdepth = -1;
void dfs(TreeNode* root, int depth) {
    if(!root)
        return ;
    if(depth > maxdepth) {
        maxdepth = depth;
        res = root->val;
    } else if (depth == maxdepth)
        res += root->val;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}

int main(int argc, char* argv[]) {

    vector<Data> v{1, 2, 3, 4, 5, nullptr, 6, 7, nullptr, nullptr, nullptr, nullptr, 8};
    TreeNode* root = Tree(v).getRoot();
    dfs(root, 0);
    std::cout << res << std::endl;
    return 0;
}
