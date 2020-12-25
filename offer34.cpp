#include <iostream>
#include "Tree.h"
vector<vector<int>> res;
vector<int> v;
int target;
void dfs(TreeNode* root, int sum) {
    if(!root) return;
    sum += root->val;
    v.push_back(root->val);
    if(sum == target && !root->left && !root->right) {
        res.push_back(v);
    }
    dfs(root->left, sum);
    dfs(root->right, sum);
    v.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    target = sum;
    dfs(root, 0);
    return res;
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {5, 4, 8, 11, nullptr, 13, 4, 7, 2, nullptr, nullptr, 5, 1});
    pathSum(t.getRoot(), 22);

    for(auto v : res) {
        for(auto val : v)
            std::cout << val << "\t";
        std::cout << std::endl;
    }
    return 0;
}
