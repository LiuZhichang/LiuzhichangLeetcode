#include <iostream>
#include "Tree.h"
#include <unordered_map>
using std::unordered_map;
class Solution {
  public:
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root, distance, ans);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int distance, int& ans) {
        if (root == nullptr) return {};
        if (root->left == nullptr && root->right == nullptr) return { 0 };

        vector<int> ret;
        auto left = dfs(root->left, distance, ans);
        for (auto& e : left) {
            if (++e > distance) continue;
            ret.push_back(e);
        }
        auto right = dfs(root->right, distance, ans);
        for (auto& e : right) {
            if (++e > distance) continue;
            ret.push_back(e);
        }

        for (auto l : left) {
            for (auto r : right) {
                ans += (l + r <= distance);
            }
        }

        for(auto i : ret)
            std::cout << i << "\t";
        std::cout << std::endl;
        return ret;
    }
};

int main(int argc, char* argv[]) {
    Tree t(vector<Data> {1, 2, 3, 4, 5, 6, 7});
    Solution s;
    int res = s.countPairs(t.getRoot(), 3);
    std::cout << res << std::endl;
    return 0;
}
