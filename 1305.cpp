#include <iostream>
#include "Tree.h"


vector<int> res;
void dfs(TreeNode* root, vector<int>& v) {
    if(!root)
        return ;
    stack<TreeNode*> s;
    while(root || !s.empty()) {
        while(root) {
            s.push(root);
            root = root->left;
        }
        TreeNode* node = s.top();
        s.pop();
        v.push_back(node->val);
        root = node->right;
    }
}
void meger(vector<int>& v1, vector<int>& v2, vector<int>& res) {
    int l_len = v1.size();
    int r_len = v2.size();
    // 1 2 4
    // 0 1 3
    int i = 0, j = 0, k = 0;
    while(i < l_len && j < r_len) {
        if(v1[i] < v2[j]) {
            res[k++] = v1[i++];
        } else {
            res[k++] = v2[j++];
        }
    }
    if(i < l_len) {
        while(i < l_len)
            res[k++] = v1[i++];
    }
    if(j < r_len) {
        while(j < r_len)
            res[k++] = v2[j++];
    }
}
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> vec1;
    vector<int> vec2;
    dfs(root1, vec1);
    dfs(root2, vec2);
    vector<int> res(vec1.size() + vec2.size());
    meger(vec1, vec2, res);
    return res;
}
int main(int argc, char* argv[]) {
    vector<Data> v1{};
    vector<Data> v2{1, 0, 3};
    Tree t1(std::ref(v1));
    Tree t2(std::ref(v2));
    vector<int> res = getAllElements(t1.getRoot(), t2.getRoot());
    for(auto item : res)
        std::cout << item << std::endl;
    return 0;
}
