#include <iostream>
#include "Tree.h"
#include <string.h>
int num[10] {0};
int res = 0;

bool isPlindaromic() {
    int count = 0;
    for(int i = 1 ; i < 10 ; i ++) {
        if(num[i] != 0) {
            if(num[i] % 2 == 1)
                ++ count;
        }
        if(count > 1)
            return false;
    }
    return true;
}

int pseudoPalindromicPaths (TreeNode* root) {
    if(!root)
        return 0;
    ++ num[root->val];
    if(!root->left && !root->right) {
        if(isPlindaromic()) {
            ++ res;
        }
    }
    pseudoPalindromicPaths(root->left);
    pseudoPalindromicPaths(root->right);
    -- num[root->val];
    return 0;
}

int main(int argc, char* argv[]) {
    Tree t(vector<Data> {9});
    pseudoPalindromicPaths(t.getRoot());

    std::cout << res << std::endl;
    return 0;
}
