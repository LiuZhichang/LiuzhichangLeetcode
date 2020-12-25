#include <iostream>
#include "List.h"

int getDecimalValue(ListNode* head) {
    int len = -1;
    ListNode* node = head;
    while(node != nullptr) {
        ++ len;
        node = node->next;
    }
    int res = 0;
    while(head != nullptr) {
        res += (head->val << (len--));
        head = head->next;
    }
    return res;
}

int main(int argc, char* argv[]) {

    List l({1, 0, 1});

    return 0;
}
