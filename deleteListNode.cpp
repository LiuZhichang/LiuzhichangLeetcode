#include <iostream>


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
    }
};

void deleteNode(ListNode* node) {
    if(node->next != nullptr) {
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;
        temp = nullptr;
    } else {
        delete node;
        node = nullptr;
    }
}

int main(int argc, char* argv[]) {



    return 0;
}
