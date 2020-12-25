#include <iostream>
#include "Tree.h"
class CBTInserter {
    vector<TreeNode*> tree;

    void bfs(TreeNode* root) {
        if(!root)
            return ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            tree.push_back(node);
            for(auto item : {
                        node->left, node->right
                    }) {
                if(item)
                    q.push(item);
            }
        }
    }
  public:
    CBTInserter(TreeNode* root) {
        bfs(root);
    }

    int insert(int v) {
        tree.push_back(new TreeNode(v));
        int node_idx = tree.size() - 1;
        int parent_idx = 0;
        if(node_idx % 2 == 0) {
            parent_idx = node_idx / 2 - 1;
            tree[parent_idx]->right = tree[node_idx];
        } else if(node_idx % 2 == 1) {
            parent_idx = node_idx / 2;
            tree[parent_idx]->left = tree[node_idx];
        }
        return tree[parent_idx]->val;
    }

    TreeNode* get_root() {
        return tree[0];
    }
};

int main(int argc, char* argv[]) {



    return 0;
}
