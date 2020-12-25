#include <iostream>
#include "Tree.h"
#include <map>
#include <unordered_map>
using std::map;
using std::unordered_map;
/*
 *
 * 如果两个数的前缀总和是相同的，
 * 那么这些节点之间的元素总和为零。
 * 进一步扩展相同的想法，
 * 如果前缀总和currSum，
 * 在节点A和节点B处相差target，
 * 则位于节点A和节点B之间的元素之和是target。
 *
*/
class Solution {
  public:
    unordered_map<int, int> m;
    int sum, res = 0;
  public:
    void dfs(TreeNode* root, int cur_sum) {
        if (root == nullptr) return;
        if(m.count(cur_sum - sum))
            res += m[cur_sum - sum];
        m[cur_sum] ++;
        if(root->left)  dfs(root->left, cur_sum + root->left->val);
        if(root->right) dfs(root->right, cur_sum + root->right->val);
        m[cur_sum] --;
    }
    int pathSum(TreeNode * root, int sum) {
        if(root == nullptr) return 0;
        this->sum = sum;
        // 构建前缀和
        m[0] = 1;
        dfs(root, root->val);
        return res;
    }
};

//dfs用来计算二叉树中符合要求的路径的长度
void dfs(TreeNode* root, int sum, int& cnt) {
    if(root == nullptr) return;
    //累计符合要求的路径个数
    if(root->val == sum) cnt++;
    dfs(root->left, sum - root->val, cnt);
    dfs(root->right, sum - root->val, cnt);
}
//用来遍历每个节点
void dfs1(TreeNode* root, int sum, int& cnt) {
    if(root == nullptr) return;
    dfs(root, sum, cnt);
    dfs1(root->left, sum, cnt);
    dfs1(root->right, sum, cnt);
}
int pathSum(TreeNode* root, int sum) {
    int cnt = 0;
    dfs1(root, sum, cnt);
    return cnt;
}
int main(int argc, char* argv[]) {
    Tree t(vector<Data> {10, 5, -3, 3, 2, nullptr, 11, 3, -2, nullptr, 1});
//    std::cout << pathSum(t.getRoot(), 8) << std::endl;
    Solution s;
    s.pathSum(t.getRoot(), 8);

    return 0;
}
