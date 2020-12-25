#include <iostream>
#include "Tree.h"

int res = 0;
bool isLeaf(TreeNode* node);
int sumOfLeftLeaves(TreeNode* root) {
    if(root == nullptr)
        return 0;
    if(isLeaf(root->left)) {
        return root->left->val + sumOfLeftLeaves(root->right);
    }
    return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
}
bool isLeaf(TreeNode* node) {
    if(!node)
        return false;
    return node->left == nullptr && node->right == nullptr;
}
int dfs(TreeNode* root) {
    if(root == nullptr || (root->left == nullptr && root->right == nullptr))
        return 0;
    int res = 0;
    int lval = 0;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while(node || !s.empty()) {
        while(node) {
            s.push(node);
            TreeNode* t = node;
            node = node->left;
            if(isLeaf(node))
                res += node->val;
        }
        TreeNode* temp = s.top();
        s.pop();
        if(temp->right)
            node = temp->right;
    }
    return res ;
}
int main(int argc, char* argv[]) {

    vector<Data> v{1, 2, 3, 4, 5};
    Tree t(v);
    TreeNode* root = t.getRoot();
    //auto vec = t.PreOrder();
    t.Print();
    // std::cout << dfs(root) << std::endl;
    //for(auto& item : vec) {
    //    std::cout << item << "\t";
    //}
    std::cout << "res: \n" <<  dfs(root) << std::endl;
    return 0;
}
