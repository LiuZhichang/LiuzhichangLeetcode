#include <iostream>
#include "Tree.h"
bool isEvenOddTree(TreeNode* root) {
    if(!root)   return false;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        int size = q.size();
        int pre = 0;
        while(size--) {
            TreeNode* node = q.front();
            if((level & 1) == 1) {
                // 1. in odd level , all item is even number
                // 2. all number are sorted by descending
                if((node->val & 1) == 1)
                    return false;
                if(pre != 0 && node->val >= pre)
                    return false;

            } else {
                // 1. in even level , all item is odd number
                // 2. all number are sorted by increment
                if((node->val & 1) != 1)
                    return false;
                if(pre != 0 && node->val <= pre)
                    return false;
            }
            pre = node->val;
            q.pop();
            for(auto item : {
                        node->left, node->right
                    })
                if(item) q.push(item);
        }
        pre = 0;
        ++ level;
    }
    return true;
}
int main(int argc, char* argv[]) {

    Tree t(vector<Data> {5, 4, 2, 3, 3, 7});
    std::cout << isEvenOddTree(t.getRoot()) << std::endl;
    return 0;
}
