#include <iostream>
#include "Tree.h"

int target_val;
int target_step;
void dfs(vector<int>& res, TreeNode* root, int step) {
    if(!root)
        return ;
    if(root->val == target_val) {
        target_step = step;
    }
    dfs(res, root->left, step + 1);
    dfs(res, root->right, step + 1);
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> res;
    target_val = target->val;
    target_step = 0;
    dfs(res, root, 1);
    return res;
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {3, 5, 1, 6, 2, 0, 8, nullptr, nullptr, 7, 4});
    distanceK(t.getRoot(), new TreeNode(5), 2);

    return 0;
}
