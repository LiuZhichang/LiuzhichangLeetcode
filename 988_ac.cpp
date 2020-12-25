#include <iostream>
#include <string>
#include <algorithm>
#include "Tree.h"
using std::string;
void helper(TreeNode* root, string& path, string& res) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        string s = path;
        s += root->val + 'a';
        std::reverse(s.begin(), s.end());
        if (!s.empty() && s < res) res = s;
        return;
    }
    path += root->val + 'a';
    helper(root->left, path, res);
    helper(root->right, path, res);
    path.pop_back();
}
string smallestFromLeaf(TreeNode* root) {
    string path;
    string res = "~";
    helper(root, path, res);
    return res;
}


int main(int argc, char* argv[]) {

    string s;



    return 0;
}
