#include <iostream>
#include "Tree.h"
#include <unordered_map>
using std::unordered_map;
class Solution {
    unordered_map<int, int> m;
    int target_val;
    int res;
    void dfs(TreeNode* root, int cur_sum) {
        if(!root)
            return;
        if(m.count(cur_sum - target_val))
            res += m[cur_sum - target_val];
        ++ m[cur_sum];
        if(root->left) dfs(root->left, cur_sum + root->left->val);
        if(root->right) dfs(root->right, cur_sum + root->right->val);
        -- m[cur_sum];
    }
  public:
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        target_val = sum;
        res = 0;
        m[0] = 1;
        dfs(root, root->val);
        return res;
    }
};
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {5, 4, 8, 11, nullptr, 13, 4, 7, 2, nullptr, nullptr, 5, 1});
    Solution s;
    std::cout << s.pathSum(t.getRoot(), 22) << std::endl;

    return 0;
}
