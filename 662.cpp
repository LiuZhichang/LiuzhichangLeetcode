#include <algorithm>
#include <iostream>
#include "Tree.h"
#include <queue>
using std::queue;
template <typename T1, typename T2>
struct pair {
    T1 first;
    T2 second;
    pair(T1 val1, T2 val2): first(val1), second(val2) {}
};
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    int ans = 1;
    q.push({root, 1});
    while (!q.empty()) {
        int sz = q.size();
        ans = std::max(int(q.back().second - q.front().second + 1), ans);
        for (int i = 0; i < sz; i++) {
            TreeNode *node = q.front().first;
            unsigned long long pos = q.front().second;
            q.pop();
            if (node->left) q.push({node->left, 2 * pos});
            if (node->right) q.push({node->right, 2 * pos + 1});
        }
    }
    return ans;
}

int main(int argc, char* argv[]) {

    Tree t(vector<Data> {1, 1, 1, 1, 1, 1, 1, nullptr, nullptr, nullptr, 1, nullptr, nullptr, nullptr, nullptr, 2, 2, 2, 2, 2, 2, 2, nullptr, 2, nullptr, nullptr, 2, nullptr, 2});
    std::cout << widthOfBinaryTree(t.getRoot()) << std::endl;
    return 0;
}
