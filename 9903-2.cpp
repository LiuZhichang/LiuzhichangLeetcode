#include "Tree.h"
TreeNode * f1 = nullptr, * f2 = nullptr;
int l1 = INT32_MIN, l2 = INT32_MAX;
void dfs(TreeNode * root, TreeNode * parent, int k, int x, int y) {
    if (!root || (f1 && f2)) return;
    if (root->val == x) {
        f1 = parent;
        l1 = k;
    } else if (root->val == y) {
        f2 = parent;
        l2 = k;
    } else {
        dfs(root->left, root, k + 1, x, y);
        dfs(root->right, root, k + 1, x, y);
    }
}
bool isCousins1(TreeNode* root, int x, int y) {
    dfs(root, 0, 0, x, y);
    return f1 != f2 && l1 == l2;
}
bool isCousins(TreeNode* root, int x, int y) {
    queue<TreeNode *> q;
    if (root) q.push(root);

    TreeNode* node = nullptr;
    TreeNode * f1 = nullptr, * f2 = nullptr;
    while (q.size()) {
        int size = q.size();
        while (size--) {
            node = q.front();
            q.pop();
            for (auto item : {
                        node->left, node->right
                    }) {
                if (!item) continue;
                if (item->val == x) f1 = root;
                if (item->val == y) f2 = root;
                q.push(item);
            }
        }
        std::cout << std::endl;
        if (f1 || f2)
            return f1 && f2 && f1 != f2;
    }
    return false;
}

int main(int argc, char* argv[]) {

    vector<Data> v{1, 2, 3, 4};
    Tree t(v);
    t.Print();
    TreeNode* root = t.getRoot();
    std::cout << isCousins(root, 4, 3) << std::endl;
    return 0;
}
