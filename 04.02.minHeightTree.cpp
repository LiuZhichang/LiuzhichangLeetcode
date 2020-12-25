#include <iostream>
#include "Tree.h"
#include <vector>
#include <stack>
#include <queue>
using std::vector;
TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.empty())
        return nullptr;
    int mid = nums.size() / 2;
    TreeNode* r = new TreeNode(nums[mid]);
    std::vector<int> left(nums.begin(), nums.end() - (nums.size() - mid));
    std::vector<int> right(nums.begin() + mid + 1, nums.end());
    r->left = sortedArrayToBST(left);
    r->right = sortedArrayToBST(right);
    return r;
}

void preOlder(TreeNode* root) {
    if(root == nullptr)
        return;
    std::cout << root->val << std::endl;
    preOlder(root->left);
    preOlder(root->right);
}

void midOlder(TreeNode* root) {
    if(root == nullptr)
        return;
    preOlder(root->left);
    std::cout << root->val << std::endl;
    preOlder(root->right);
}

void foreachPreOlder(TreeNode* root) {
    std::stack<TreeNode*> stack;
    TreeNode* node = root;
    while(node != nullptr || !stack.empty()) {
        while(node != nullptr) {
            std::cout << node->val << std::endl;
            stack.push(node);
            node = node->left;
        }
        if(!stack.empty()) {
            node = stack.top();
            stack.pop();
            node = node->right;
        }
    }
}

void levelOrder(TreeNode* root) {
    std::queue<TreeNode*> queue;
    queue.push(root);
    while(!queue.empty()) {
        root = queue.front();
        queue.pop();
        std::cout << root->val << std::endl;
        if(root->left != nullptr) queue.push(root->left);
        if(root->right != nullptr) queue.push(root->right);
    }
}

int main(int argc, char* argv[]) {

    std::vector<int> nums {-3, -10, 0, 3, 5};
    TreeNode* root = sortedArrayToBST(nums);
    std::cout << "-------------" << std::endl;
    levelOrder(root);
    return 0;
}
