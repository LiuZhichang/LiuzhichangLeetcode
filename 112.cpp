#include <cstdint>
#include <iostream>
#include "Tree.h"
#include <map>
#include <set>
bool hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr)
        return false;
    if(root == nullptr)
        return 0;
    stack<TreeNode*> nodes;
    stack<int> nums;
    int flag = -1;
    while(root || !nodes.empty()) {
        while(root) {
            nodes.push(root);
            if(flag == -1) {
                flag = 0;
                nums.push(root->val);
            } else
                nums.push(root->val + nums.top());
            // if(root->left == nullptr && root->right == nullptr)
            std::cout << nodes.top()->val << " " << nums.top() << std::endl;
            root = root->left;
        }

        TreeNode* node = nodes.top();
        nodes.pop();
        int tmp = nums.top();
        if(node)
            nums.pop();
        root = node->right;
    }
    return false;
}

std::map<int, int> m;

bool dfs(TreeNode* root, int sum, int target) {
    if(root == nullptr)
        return false;

    if(sum == -1)
        sum = root->val;
    else
        sum += root->val;

    std::cout << sum << std::endl;
    if(root->left == nullptr && root->right == nullptr) {
        return (sum == target);
    }

    bool l = dfs(root->left, sum, target);
    bool r = dfs(root->right, sum, target);
    return l || r;
}

int main(int argc, char* argv[]) {

    vector<Data> v{5, 4, 8, 11, nullptr, 13, 4, 7, 2, nullptr, nullptr, nullptr, 1};
    Tree t(v);
    TreeNode* root = t.getRoot();

    // std::cout << hasPathSum(root, 22) << std::endl;
//    dfs(root, root->val, 22);
    std::cout <<  dfs(root, -1, 26) << std::endl;
    std::set<int> s;

    return 0;
}
