#pragma once
#include <vector>
#include <iostream>
using std::vector;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class List {
  public:

    typedef ListNode type;
    typedef ListNode* ptr;
    ptr begin;
    ptr end;
    std::size_t len;
    List(const vector<int>& v);
    List(vector<int>&& v);
    void operator = (std::vector<int>& vector) {

    }
    ListNode* getHead() {
        return begin->next;
    }
    const std::size_t size() const {
        return len;
    }
    void Print();
};

List::List(const vector<int>& v) {
    begin = new type();
    end = begin;
    len = 0;
    for(auto item : v) {
        ++ len;
        auto node = new type(item);
        end->next = node;
        end = node;
    }
}

List::List(vector<int>&& v) {
    begin = new type();
    end = begin;
    len = 0;
    for(auto item : v) {
        ++ len;
        auto node = new type(item);
        end->next = node;
        end = node;
    }
}

void List::Print() {
    auto node = (begin->next) ? begin->next : nullptr;
    while(node) {
        std::cout << node->val << "\t";
        node = node->next;
    }
    std::cout << std::endl;

}

void ListPrint(ListNode* node) {
    while(node) {
        std::cout << node->val << "\t";
        node = node->next;
    }
    std::cout << std::endl;
}
