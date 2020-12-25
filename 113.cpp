#include <iostream>
#include "Tree.h"

int target;
vector<vector<int>> res;
vector<int> v;
void PrintItem(vector<int>& v) {
    for(auto item : v)
        std::cout << item << "\t";
    std::cout << std::endl;
}
void dfs(TreeNode* root, int sum) {
    if(!root)
        return ;
    sum += root->val;
    v.push_back(root->val);
    if(!root->left && !root->right) {
        PrintItem(v);
        std::cout << sum << std::endl;
        v.pop_back();
        return ;
    }
    dfs(root->left, sum);
    dfs(root->right, sum);
    v.pop_back();
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if(!root)
        return res;
    target = sum;
    dfs(root, 0);
    return res;
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {5, 4, 8, 11, nullptr, 13, 4, 7, 2, nullptr, nullptr, 5, 1});
    pathSum(t.getRoot(), 22);

    return 0;
}
