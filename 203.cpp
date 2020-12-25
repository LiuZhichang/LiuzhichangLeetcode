#include <iostream>
#include "List.h"

ListNode* removeElements(ListNode* head, int val) {
    ListNode* node = head;
    ListNode* pre = new ListNode;
    while(node) {
        if(node->val == val) {
            node = node->next;
            pre->next = node;
            continue;
        }
        pre = node;
        node = node->next;
    }
    return head ? head : pre->next;
}

int main(int argc, char* argv[]) {

    List l({1, 2, 6, 3, 4, 5, 6});

    auto res = removeElements(l.getHead(), 6);

    ListPrint(res);
    return 0;
}
