#include "List.h"

ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
	ListNode* list2_end = list2;
	while(list2_end->next) list2_end = list2_end->next;

	ListNode* left = nullptr,*right = nullptr;
	ListNode* node = list1;
	int n = 1;
	while(n < a) {
		++n;
		node = node->next;
	}
	left = node;
	while(n <= b) {
		++n;
		node = node->next;
	}
	right = node->next;

	left->next = list2;
	list2_end->next = right;

	return list1;
}


int main(int argc, char *argv[]) {
	List l1{0,1,2,3,4,5};
	List l2{10000,10001,10002};
	auto head = mergeInBetween(l1.getHead(), 3, 4, l2.getHead());
	ListPrint(head);
	return 0;
}
