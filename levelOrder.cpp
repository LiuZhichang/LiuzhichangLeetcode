#include <iostream>
#include <queue>
#include "Tree.h"
#include <vector>
void levelOrder(TreeNode* node) {
    std::queue<TreeNode*> queue;
    std::vector<int> vec;
    if(node != nullptr)
        queue.push(node);
    while(!queue.empty()) {
        vec.push_back(queue.front()->val);
        if(queue.front()->left != nullptr)
            queue.push(queue.front()->left);
        if(queue.front()->right != nullptr)
            queue.push(queue.front()->right);
        queue.pop();
    }
}

int main(int argc, char* argv[]) {



    return 0;
}
