#include <cstdint>
#include <iostream>
#include "Tree.h"

int target;
int count;
int maxcount;

void numCount(vector<int>& res, int num) {
    if(num == target) {
        ++ count;
    } else {
        target = num;
        count = 1;
    }
    if(count == maxcount) {
        res.push_back(num);
    }
    if(count > maxcount) {
        maxcount = count;
        res = vector<int> {num};
    }
}

vector<int> findMode(TreeNode* root) {
    vector<int> res;

    stack<TreeNode*> s;

    while(root || !s.empty()) {
        while(root) {
            s.push(root);
            root = root->left;
        }
        if(s.top())
            numCount(res, s.top()->val);
        root = s.top() ->right;
        s.pop();

    }


    return res;
}

int main(int argc, char* argv[]) {

    vector<Data> v{5, 3, 6, nullptr, 4, nullptr, nullptr };
    Tree t(v);
    TreeNode* root = t.getRoot();

    findMode(root);
    return 0;
}
