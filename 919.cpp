#include <iostream>
#include "Tree.h"

/*
	完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大）的，并且所有的节点都尽可能地集中在左侧。
	设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：
    CBTInserter(TreeNode root) 使用头节点为 root 的给定树初始化该数据结构；
    CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v 。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值；
    CBTInserter.get_root() 将返回树的头节点。
*/

class CBTInserter {
    vector<TreeNode*> tree;
  private:
    void bfs(TreeNode* root) {
        if(!root)
            return ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            tree.push_back(node);
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
    }
  public:
    CBTInserter(TreeNode* root) {
        bfs(root);
    }

    int insert(int v) {
        tree.push_back(new TreeNode(v));
        for(auto node : tree)
            std::cout << node->val << "\t";
        std::cout << std::endl;
        int newIdx = tree.size() - 1;
        int parentIdx = (newIdx % 2 == 0) ? newIdx / 2 - 1 : newIdx / 2;
        if(!tree[parentIdx]->left)
            tree[parentIdx]->left = tree[newIdx];
        if(!tree[parentIdx]->right)
            tree[parentIdx]->left = tree[newIdx];
        return tree[parentIdx]->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }
};

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {1, 2, 3, 4, 5, 6});
    t.Print();
    CBTInserter ci(t.getRoot());
    std::cout << ci.insert(7) << std::endl;
    return 0;
}
