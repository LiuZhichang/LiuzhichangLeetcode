#include <iostream>
#include "Tree.h"
#include "List.h"


void addItem(ListNode* node, int val) {
    ListNode* newNode = new ListNode(val);
    node->next = newNode;
    node = newNode;
}

vector<ListNode*> listOfDepth(TreeNode* tree) {
    vector<ListNode*> res;
    if(!tree)
        return res;
    queue<TreeNode*> q;
    q.push(tree);
    ListNode* head = new ListNode(0);
    ListNode* list_node = head;
    while(!q.empty()) {
        int size = q.size();
        head->next = nullptr;
        list_node = head;
        while(size--) {
            TreeNode* node = q.front();
            q.pop();
            ListNode* newNode = new ListNode(node->val);
            list_node->next = newNode;
            list_node = newNode;
            for(auto& item : {
                        node->left, node->right
                    }) {
                if(item)
                    q.push(item);
            }
        }
        ListNode* temp = head->next;
        res.push_back(temp);
    }


    return res;
}


int main(int argc, char* argv[]) {

    Tree t(vector<Data> {1, 2, 3, 4, 5, nullptr, 7, 8});
    t.Print();

    vector<ListNode*> v = listOfDepth(t.getRoot());
    for(auto node : v) {
        while(node) {
            std::cout << node->val << "\t";
            node = node->next;
        }
        std::cout << std::endl;
    }
    return 0;
}
