#include <iostream>
#include <string>
#include "Tree.h"

using std::string;
// １：字典序最小（需要比较）
// ２：从叶子节点到根（也就是说需要存储叶子节点到根的字符串）
// ３：０－２５　代表　ａ－ｚ　'a' + node->val
// ４：字符串中任何较短的前缀在字典序上都是较小的

string compare(string& s1, string& s2) {
    return s1.compare(s2) < 0 ? s1 : s2;
}

string dfs(TreeNode* root) {
    if(!root || (!root->left && !root->right))
        return string(1, root->val + 97);
    string l = dfs(root->left) + string(1, root->val + 97);
    string r = dfs(root->right) + string(1, root->val + 97);
    return compare(l, r);
}

string smallestFromLeaf(TreeNode* root) {
    return dfs(root);
}
int main(int argc, char* argv[]) {
    Tree t(vector<Data> {0, nullptr, 1});
    smallestFromLeaf(t.getRoot());
    return 0;
}
