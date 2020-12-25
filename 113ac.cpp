#include <iostream>
#include "Tree.h"
class Solution {
    vector<vector<int>> res;
    vector<int> v;
    int target;
  public:
    void dfs(TreeNode* root, int sum) {
        if(!root)
            return ;
        sum += root->val;
        v.push_back(root->val);
        if(sum == target && root->left == nullptr && root->right == nullptr) {
            res.push_back(v);
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
};
int main(int argc, char* argv[]) {



    return 0;
}
