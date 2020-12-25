#include <cstdlib>
#include <iostream>
#include "Tree.h"

void bfs(TreeNode* root) {
}

bool isCousins(TreeNode* root, int x, int y) {
    if(!root)
        return false;
    if(root->val == x || root->val == y)
        return true;
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* lparent = nullptr;
    TreeNode* rparent = nullptr;
    while(!q.empty()) {
        int size = q.size();
        TreeNode* node = nullptr;
        while(size--) {
            node = q.front();
            q.pop();
            std::cout << node->val << "\t";
            for(auto item : {
                        node->left, node->right
                    }) {
                if(!node)
                    continue;
                q.push(node);
            }
        }
        std::cout << std::endl;
    }
    return false;
}

//queue<TreeNode *> q;
//if (root) q.push(root);
//
//TreeNode * f1 = nullptr, * f2 = nullptr;
//while (q.size()) {
//    int size = q.size();
//    while (size--) {
//        root = q.front();
//        q.pop();
//        for (auto c : {
//                    root->left, root->right
//                }) {
//            if (!c) continue;
//            if (c->val == x) f1 = root;
//            if (c->val == y) f2 = root;
//            q.push(c);
//        }
//    }
//    if (f1 || f2)
//        return f1 && f2 && f1 != f2;
//}
//return false;
int main(int argc, char* argv[]) {

    vector<Data> v{1, 2, 3, 4};
    Tree t(v);
    t.Print();
    TreeNode* root = t.getRoot();
    std::cout << isCousins(root, 4, 3) << std::endl;
    return 0;
}
