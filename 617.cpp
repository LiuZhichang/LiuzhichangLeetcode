#include <iostream>
#include "Tree.h"
#include <queue>
using std::queue;
TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
    if(t1 == nullptr || t2 == nullptr)
        return t1 == nullptr ? t2 : t1;
    t1->val += t2->val;
    t1->left = mergeTrees(t1->left, t2->left);
    t1->right = mergeTrees(t1->right, t2->right);

    return t1;
}


int main(int argc, char* argv[]) {



    return 0;
}
