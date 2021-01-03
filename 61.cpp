#include "List.h"

ListNode* rotateRight(ListNode* head, int k) {
    if(!head || !k) return head;

    ListNode* old_end = head;
    int len = 1 ;
    while(old_end->next) {
        old_end = old_end->next;
        ++len;
    }

    old_end->next = head;
    ListNode* new_end = head;
    for(int i = 0 ; i < len - k % len - 1 ; ++i)
        new_end = new_end->next;
    ListNode* new_head = new_end->next;
    new_end->next = nullptr;

    return new_head;
}

int main(int argc, char *argv[]) {
    List l{1, 2, 3, 4, 5};
    auto head = rotateRight(l.getHead(), 2);
    ListPrint(head);
    return 0;
}
