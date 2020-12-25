#include <iostream>
#include <map>
#include <set>
#include "Tree.h"

std::set<int> se;
void dfs(TreeNode* root, int k, bool& flag) {
    if(root == nullptr)
        return;
    if(flag == true)
        return;
    if(se.find(k - root->val) != std::end(se)) {
        flag = true;
    }

    se.insert(root->val);
    dfs(root->left, k, flag);
    dfs(root->right, k, flag);
}

bool findTarget_dfs(TreeNode* root, int k) {
    if(root == nullptr)
        return false;
    bool flag = false;
    dfs(root, k, flag);
    return flag;
}

bool findTarget(TreeNode* root, int k) {
    if(root == nullptr)
        return false;
    std::set<int> s;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if(s.find((k - node->val)) != std::end(s)) {
            return true;
        }
        s.insert(node->val);
        if(node->left != nullptr )
            q.push(node->left);
        if(node->right != nullptr)
            q.push(node->right);
    }
    return false;
}

int main(int argc, char* argv[]) {

    vector<Data> v{5, 3, 6, 2, 4, nullptr, 7};
    TreeNode* root = Tree(v).getRoot();
    std::cout << findTarget_dfs(root, 9) << std::endl;
    return 0;
}
