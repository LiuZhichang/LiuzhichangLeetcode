#include <iostream>
#include "Tree.h"
#include <stack>

using std::stack;

int sumNumbers(TreeNode* root) {
    int res = 0;
    int level = 0;
    stack<TreeNode*> s;
    if(root != nullptr)
        s.push(root);
    else
        return root->val;

    while(!s.empty()) {
        int size = s.size();
        for(int i = 0 ; i < size ; i++) {
            auto node = s.top();
            std::cout << node->val << "\t";
            s.pop();
            if(node->right != nullptr) {
                s.push(node->right);
            }
            if(node->left != nullptr) {
                s.push(node->left);
            }
        }
        std::cout << std::endl;
    }
    return res;
}

int res = 0;
int level(TreeNode* root) {
    if(root != nullptr) {
        int sum = root->val;
        int left = level(root->left);
        int right = level(root->right);
        int level = left > right ? left + 1 : right + 1;
        std::cout << "level : " << level << std::endl;
        std::cout << "val : " << level << std::endl;
        std::cout << "sum : " << sum << std::endl;
        return level;
    }
    return 0;
}

int sumNumbers1(TreeNode* root) {

}

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);

    level(root);

    std::cout << std::pow()
              return 0;
}
