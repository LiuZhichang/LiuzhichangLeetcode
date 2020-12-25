#include <cstdint>
#include <iostream>
#include "Tree.h"
#include <stack>
using std::stack;
int getMinimumDifference(TreeNode* root) {
    stack<TreeNode*> s;
    int pre = -1;
    int ans = INT32_MAX;
    while(root != nullptr || !s.empty()) {
        while(root != nullptr) {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        if(pre == -1) {
            pre = root->val;
        } else {
            ans = std::min(ans, root->val - pre);
            pre = root->val;
        }
        root = root->right;
    }
    return ans;
}

void dfs(TreeNode* root, int pre, int res) {
    if(root == nullptr)
        return;
    dfs(root->left, pre, res);
    if(pre == -1) {
        pre = root->val;
    } else {
        res = std::min(res, root->val - pre);
        pre = root->val;
    }
    dfs(root->right, pre, res);
}

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    getMinimumDifference(root);


    return 0;
}
