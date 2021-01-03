#include "List.h"

ListNode* getIntersectionNode(ListNode* nodea,ListNode* nodeb) {
	ListNode* a = nodea;
	ListNode* b = nodeb;

	while( a != b ) {
		a = a ? a->next : nodea;
		b = b ? b->next : nodeb;
	}

	return a;
}
