#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};



ListNode* megerTowLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode;
    ListNode* tail = head;

    while(l1 != nullptr && l2 != nullptr) {
        if (l1->val <= l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1->next != nullptr) {
        tail->next = l1;
    } else if (l2->next != nullptr) {
        tail->next = l2;
    }
    ListNode* res = head->next;
    delete head;
    return res;
}

int main(int argc, char* argv[]) {



    return 0;
}
