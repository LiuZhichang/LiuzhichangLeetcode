#include "Tree.h"
#include <iostream>

TreeNode* buildTree(vector<int>& v, int l, int r) {

    if(l > r)
        return nullptr;
    TreeNode* root = new TreeNode(v[r]);
    if(l == r)
        return root;

    int M = l - 1;
    int left = l;
    int right = r - 1;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);
        if(v[mid] < v[r]) {
            std::cout << v[mid] << "\t";
            M = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    std::cout << std::endl;
    root->left = buildTree(v, l, M);
    root->right = buildTree(v, M + 1, r - 1);
    return root;
}

void dfs(TreeNode* root) {
    if(!root)
        return ;
    dfs(root->left);
    std::cout << root->val << std::endl;
    dfs(root->right);
}

int main(int argc, char* argv[]) {

    vector<int> v{1, 3, 2, 7, 8, 6, 4};
    TreeNode* root = buildTree(v, 0, v.size() - 1);
    dfs(root);
    return 0;
}
