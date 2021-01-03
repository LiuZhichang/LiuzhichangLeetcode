#include "List.h"

ListNode* left;

bool traverse(ListNode* right) {
	if(!right) return true;

	bool res = traverse(right->next);
	res = res && (left->val == right->val);
	left = left->next;
	return res;
}

bool isPalindrome(ListNode* head) {
	left = head;
	return traverse(head);
}
