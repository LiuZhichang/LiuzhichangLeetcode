#include <ios>
#include <iostream>
#include <cmath>
#include <math.h>
#include <queue>
#include "Tree.h"

using std::queue;




/**
 *	给出一棵二叉树，其上每个结点的值都是 0 或 1 。
 *	每一条从根到叶的路径都代表一个从最高有效位开始的二进制数。
 *	例如，如果路径为 0 -> 1 -> 1 -> 0 -> 1，那么它表示二进制数 01101，也就是 13 。
 *	对树上的每一片叶子，我们都要找出从根到该叶子的路径所表示的数字。
 *	以 10^9 + 7 为模，返回这些数字之和。
 */
int decimal(int binary) {
    int res = 0;
    int count = 0;
    while(binary) {
        int mod = binary % 10;
        binary /= 10;
        res += mod * pow(2, count);
        ++ count;
    }
    return res;
}

int sumRootToLeaf(TreeNode* root) {
    if(root == nullptr)
        return 0;
    int res = 0;
    queue<TreeNode*> qnode;
    queue<int> qbinary;

    qnode.push(root);
    qbinary.push(root->val);

    while(!qnode.empty()) {
        auto node = qnode.front();
        int binary = qbinary.front();
        qnode.pop();
        qbinary.pop();
        if(node->left == nullptr && node->right == nullptr) {
            res += binary;
        } else {
            if(node->left != nullptr) {
                qnode.push(node->left);
                qbinary.push(binary * 2 + node->left->val);
            }
            if(node->right != nullptr) {
                qnode.push(node->right);
                qbinary.push(binary * 2 + node->right->val);
            }
        }

    }

    return res;
}
int main(int argc, char* argv[]) {
    // (100) + (101) + (110) + (111)
    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(0);
    root->right = new TreeNode(1);


    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);

    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);

    // std::cout << sumRootToLeaf(root) << std::endl;
    // std::cout << std::ios::binary <<  (res << 1) << std::endl;

    sumRootToLeaf(root);


    return 0;
}
