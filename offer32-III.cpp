#include <iostream>
#include "Tree.h"

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<TreeNode*> q;
    int level = 0;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        int i = 0;
        vector<int> v(size);
        while(size--) {
            TreeNode* node = q.front();
            q.pop();
            if(level % 2 == 0)
                v[i] = node->val;
            else if(level % 2 == 1)
                v[size] = node->val;
            for(auto child : {
                        node->left, node->right
                    }) {
                if(child)
                    q.push(child);
            }
            ++ i;
        }
        ++ level;
        res.push_back(v);
    }

    return res;
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {3, 9, 20, 12, 13, 15, 7});
    vector<vector<int>> res = levelOrder(t.getRoot());

    for(auto v : res) {
        for(auto item : v) {
            std::cout << item << "\t";
        }
        std::cout << std::endl;
    }

    return 0;
}
