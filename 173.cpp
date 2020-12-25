#include <cstdlib>
#include <iostream>
#include "Tree.h"
class BSTIterator {
    vector<int> v;
    int idx;
    int size;
  public:
    BSTIterator(TreeNode* root) {
        stack<TreeNode*> s;
        while(root || !s.empty()) {
            while(root) {
                s.push(root);
                root = root->left;
            }
            TreeNode* node = s.top();
            s.pop();
            if(node) {
                std::cout << node->val << std::endl;
            }
            root = node->right;
        }

        idx = 0;
        size = v.size();
    }

    /** @return the next smallest number */
    int next() {
        -- size;
        return v[idx];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return size != 0;
    }
};


int main(int argc, char* argv[]) {

    return EXIT_SUCCESS;
}
