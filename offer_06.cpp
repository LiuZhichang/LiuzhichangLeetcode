#include <iostream>
#include <vector>
#include "List.h"

using std::vector;

vector<int> reversePrint(ListNode* head) {
    ListNode* node = head;
    int len = 0;
    while(node != nullptr) {
        ++len;
        node = node->next;
    }
    std::vector<int> res(len);
    int idx = res.size() - 1;
    while(head != nullptr) {
        res[idx] = head->val;
        -- idx;
        head = head->next;
    }
    return res;
}
int main(int argc, char* argv[]) {

    List l({1, 3, 2});

    auto res = reversePrint(l.getHead());

    for(auto it : res)
        std::cout << it << "\t";
    std::cout << std::endl;

    return 0;
}
