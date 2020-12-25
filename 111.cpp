#include <iostream>
#include "Tree.h"
int depth(TreeNode* root) {
    if(root) {
        int l = depth(root->left);
        int r = depth(root->right);
        return l > r ? l + 1 : r + 1;
    }
    return 0;
}
int maxnum(vector<int>& nums) {
    int max = INT32_MIN;
    int index = 0;
    for(int i = 0 ; i < nums.size() ; i++) {
        if(nums[i] > max) {
            max = nums[i];
            index = i;
        }
    }
    return index;
}
int main(int argc, char* argv[]) {

    vector<int> v{3, 2, 1, 6, 0, 5};
    int idx = maxnum(v);
    vector<int> l(v.begin(), v.begin() + idx);
    vector<int> r(v.begin() + idx + 1, v.end());
    for(auto item : r)
        std::cout << item << std::endl;
    return 0;
}
