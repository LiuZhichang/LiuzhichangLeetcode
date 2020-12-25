#include <cstdlib>
#include <iostream>
#include "Tree.h"

int res = 0;
TreeNode* flag;
int dfs(TreeNode* root) ;
int findTilt(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }
    flag = root;
    dfs(root);
    std::cout << res << std::endl;
    return 0;
}

int dfs(TreeNode* root) {
    if(root == nullptr)
        return 0;
    //if(root->left == nullptr && root->right == nullptr) {
    //    return root->val;
    //}
    int left = dfs(root->left);
    int right = dfs(root->right);
    int abs = std::abs(left - right);
    res += abs;
    return left + right + root->val;
}

int main(int argc, char* argv[]) {

    vector<Data> v{4, 2, 9, 3, 5, nullptr, 7};
    TreeNode* root = Tree(v).getRoot();

    findTilt(root);

    return 0;
}
