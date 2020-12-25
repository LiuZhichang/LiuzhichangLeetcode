#include <iostream>
#include "Tree.h"


// 给你一棵二叉树，请你返回满足以下条件的所有节点的值之和：
// 该节点的祖父节点的值为偶数。（一个节点的祖父节点是指该节点的父节点的父节点。）
// 如果不存在祖父节点值为偶数的节点，那么返回 0 。


int sumEvenGrandparent(TreeNode* root) {
    if(!root)
        return 0;
    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        vector<int> v;
        while(size--) {
            TreeNode* node = q.front();
            q.pop();
            std::cout << node->val << "\t";
            for(auto& children : {
                        node->left, node->right
                    }) {
                if(children)
                    q.push(children);
            }
        }
        std::cout << std::endl;
    }
    return res;
}


int res = 0;
int dfs(TreeNode* gradfather, TreeNode* parent, TreeNode* node) {
    if(node == nullptr)
        return 0;
    if(gradfather->val % 2 == 0)
        res += node->val;
    dfs(parent, node, node->left);
    dfs(parent, node, node->right);
    return res;
}

int main(int argc, char* argv[]) {

    vector<Data> v{6, 7, 8, 2, 7, 1, 3, 9, nullptr, 1, 4, nullptr, nullptr, nullptr, 5};
    Tree t(v);
//    t.Print();
//    TreeNode* root = t.getRoot();
    TreeNode* parent = new TreeNode(1);
    return 0;
}
