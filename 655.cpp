#include <iostream>
#include "Tree.h"
#include <string>
using std::string;

int depth(TreeNode* root) {
    if(root) {
        int l = depth(root->left);
        int r = depth(root->right);
        return l > r ?
               l + 1 :
               r + 1;
    }
    return 0;
}
void dfs(vector<vector<string>>& res, TreeNode* root, int dep, int begin, int end) {
    if(!root)
        return;
    int mid = (begin + end) / 2;
    res[dep][mid] = std::to_string(root->val);
    dfs(res, root->left, dep + 1, begin, mid - 1);
    dfs(res, root->right, dep + 1, mid + 1, end);
}
vector<vector<string>> printTree(TreeNode* root) {
    int dep = depth(root);
    int row = dep;
    int col = (1 << dep) - 1;
    vector<vector<string>> res(row, vector<string>(col, ""));
    dfs(res, root, 0, 0, col);
    return res;
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {1, 2, 3, nullptr, 4});
    vector<vector<string>> res = printTree(t.getRoot());
    for(auto v : res) {
        for(auto str : v)
            std::cout << str << "\t";
        std::cout << std::endl;
    }
    return 0;
}
