#include <iostream>
#include "Tree.h"
#include <string>
using std::string;

string tree2str1(TreeNode* root) {
    string res = "";
    if(root == nullptr)
        return res;
    stack<TreeNode*> s;
    TreeNode* node = root;
    while(node || !s.empty()) {
        string suffix = "";
        while(node) {
            s.push(node);
            res += std::to_string(node->val);
            TreeNode* rnode = node->right;
            node = node->left;
        }
        if(suffix != "")
            std::cout << suffix << std::endl;

        res += suffix;
        TreeNode* temp = s.top();
        s.pop();
        node = temp->right;
    }
    return res;
}
string tree2str(TreeNode* t) {
    if(t == nullptr)
        return "";
    if(t->left == nullptr && t->right == nullptr)
        return std::to_string(t->val) + "";
    if(t->right == nullptr)
        return std::to_string(t->val) + "(" + tree2str(t->left) + ")";
    return std::to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
}
int main(int argc, char* argv[]) {

    vector<Data> v{1, 2, 3, 4};
    Tree t(v);
    TreeNode* root = t.getRoot();
    t.Print();
    std::cout << tree2str(root) << std::endl;
    // 1(2()(4))(3)

    return 0;
}
