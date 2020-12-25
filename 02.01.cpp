#include <iostream>
#include <vector>
#include <set>
#include "List.h"

using std::set;

ListNode* removeDuplicateNodes(ListNode* head) {
    set<int> visit;
    ListNode* node = head;
    ListNode* pre;
    while(node) {
        if(visit.count(node->val)) {
            node = node->next;
            pre->next = node;
            continue;
        } else {
            visit.insert(node->val);
        }
        pre = node;
        node = node->next;
    }
    return head;
}

int main(int argc, char* argv[]) {

    List l({1, 2, 3, 3, 2, 1, 2});
    auto res = removeDuplicateNodes(l.getHead());

    while(res) {
        std::cout << res->val << "\t";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
