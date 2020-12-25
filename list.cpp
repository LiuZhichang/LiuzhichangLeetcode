
#pragma once
#include <cstdio>

namespace list {

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr) {}
};

ListNode* head = nullptr;
ListNode* end;

void add(int val) {
    if(head == nullptr) {
        head = new ListNode(val);
        end = head;
    } else {
        ListNode* node = new ListNode(val);
        end->next = node;
        end = node;

    }
}

void print(ListNode* node) {
    ListNode* item = node;
    printf("%s\n", "list item :");
    while(item != nullptr) {
        printf("%d\t", item->val);
        item = item->next;
    }
}

template <ListNode* func(ListNode* head), int val = 5>
void test() {
    for(int i = 1 ; i <= val ; i++)
        list::add(i);
    ListNode* list = func(head);
    list::print(list);
}
}
