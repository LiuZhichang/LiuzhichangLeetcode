#include <iostream>
#include <vector>
#include "List.h"

ListNode* middleNode(ListNode* head) {
    ListNode* slow, *fast;
    slow = fast = head;
    while(fast != nullptr && fast->next != nullptr ) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

int main(int argc, char* argv[]) {

    List l({1, 2, 3, 4, 5, 6});

    ListNode* node = middleNode(l.getHead());
    while(node) {
        std::cout << node->val << "\t";
        node = node->next;
    }
    std::cout << std::endl;

    return 0;
}
