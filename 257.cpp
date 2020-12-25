#include <vector>
#include <string>
#include "Tree.h"

using std::vector;
using std::string;
vector<string> res;
string dfs(TreeNode* root, string str) {

    if(root == nullptr) {
        return "";
    }
    str += std::to_string(root->val);
    if(root->left != nullptr || root->right != nullptr)
        str += "->";
    if(root->left == nullptr && root->right == nullptr) {
        res.push_back(str);
        return str;
    } else
        return dfs(root->left, str) + dfs(root->right, str);
}
vector<string> binaryTreePaths(TreeNode* root) {
    dfs(root, "");
    return res;
}
