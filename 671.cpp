#include <iostream>
#include "Tree.h"
int findSecondMinimumValue(TreeNode* root) {
    if(root == NULL || root->left == NULL) {
        return -1;
    }
    int l = root->left->val;
    int r = root->right->val;

    if(l == root->val) {
        l = findSecondMinimumValue(root->left);

    }
    if(r == root->val) {
        r = findSecondMinimumValue(root->right);

    }
    if(l == -1 && r == -1) return -1; //返回两个-1，说明左右子节点时一样的
    if(l == -1) return r; //根节点的左节点返回-1，说明左半部分的节点全为一致，即和根节点一样，则第二小为右节点。
    else if(r == -1) return l; //根节点的右节点返回-1，说明右半部分的节点全为一致，即和根节点一样，则第二小为左节点。
    else return std::min(l, r); //不同时为-1，说明找到第二小，此时在l,r取最小值即可
}
int main(int argc, char* argv[]) {



    return 0;
}
