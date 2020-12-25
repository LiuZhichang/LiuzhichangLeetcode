#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x), next(nullptr) {}

};

ListNode* listreverse(ListNode* head) {
    ListNode* list = new ListNode(0);
    ListNode* node = head;
    while(node != nullptr) {
        ListNode* temp = node;
        node = node->next;
        temp->next = list;
        list = temp;
    }

    return list;
}

ListNode* reverse(ListNode* list) {
    ListNode* head = list;
    ListNode* node = list->next;
    head->next = nullptr;
    while(node->next != nullptr) {
        ListNode* item = node;
        item->next = head;
        node = node->next;
        head = item;
    }
    return head;
}

int main(int argc, char* argv[]) {

    ListNode* head = new ListNode(0);
    ListNode* one = new ListNode(1);
    ListNode* two = new ListNode(2);
    ListNode* three = new ListNode(3);
    ListNode* four = new ListNode(4);

    head->next = one;
    one->next = two;
    two->next = three;
    three->next = four;

    ListNode* list = reverse(head);

    while(list != nullptr) {

        std::cout << head->val << std::endl;
        head = head->next;

    }

    return 0;
}
