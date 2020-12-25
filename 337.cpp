#include <iostream>
#include "Tree.h"

int rob(TreeNode* root) {
    if(!root)
        return 0;
    int even_val = 0;
    int odd_val = 0;
    int level = 1;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        std::cout << level << std::endl;
        while(size -- ) {
            TreeNode* node = q.front();
            q.pop();
            if(level % 2 == 1) {
                even_val += node->val;
            } else if(level % 2 == 0) {
                odd_val += node->val;
            }
            for(auto item : {
                        node->left, node->right
                    }) {
                if(item)
                    q.push(item);
            }
        }
        std::cout << "even_val : " << even_val << std::endl;
        std::cout << "odd_val : " << odd_val << std::endl;
        ++ level;
    }
    return (even_val > odd_val) ? even_val : odd_val;
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {4, 1, nullptr, 2, nullptr, 3});
    t.Print();
    rob(t.getRoot());

    return 0;
}
