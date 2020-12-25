#include <iostream>
#include <utility>
#include "Tree.h"
bool isCompleteTree(TreeNode* root) {
    if(!root)
        return true;
    queue<TreeNode*> q;
    q.push(root);
    bool isnull = false;
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if(!node) {
            isnull = true;
            continue;
        } else if(isnull) {
            return false;
        }
        for(auto item : {
                    node->left, node->right
                })
            q.push(item);
    }
    return true;
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {1, 2, 3, 4, 5, nullptr, 7});
    std::cout << isCompleteTree(t.getRoot()) << std::endl;

    return 0;
}
