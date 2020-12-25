#include <algorithm>
#include <iostream>
#include "Tree.h"
#include <set>

vector<TreeNode*> res;
vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    if(!root)
        return res;
    queue<TreeNode*> q;
    q.push(root);
    res.push_back(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
        if(std::find(to_delete.begin(), to_delete.end(), node->val) != to_delete.end()) {
            //        if(node->left)
            //            res.push_back(node->left);
            //        if(node->right)
            //            res.push_back(node->right);
            //        node = nullptr;
            node = nullptr;
        }
    }

    return res;
}

using std::set;
set<int> s;
TreeNode* dfs(TreeNode* root, bool is_root) {
    if(!root)
        return nullptr;
    bool del = s.count(root->val);
    if(!del && is_root)
        res.push_back(root);
    root->left = dfs(root->left, del);
    root->right = dfs(root->right, del);
    return del ? nullptr : root;
}
//		1
//	2	   null
// 4 3
int main(int argc, char* argv[]) {
    Tree t(vector<Data> {1, 2, 3, 4, 5, 6, 7});
    vector<int> l_delete{3, 5};
    s = set<int>(l_delete.begin(), l_delete.end());
    t.Print();
    dfs(t.getRoot(), true);
    for(auto node : res)
        TreeLevelOrder(node);
    return 0;
}
