#include "List.h"
#include <iostream>

/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

示例:

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
*/

// 递归
ListNode* reverse(ListNode* node){
	if(node->next == nullptr) return node;
	ListNode* last = reverse(node->next);
	node->next->next = node;
	node->next = nullptr;

	return last;
}

// 迭代

ListNode* reverse_(ListNode* node){
	ListNode* pre,*cur,*ntx;
	pre = nullptr,cur = ntx = node;

	while(cur != nullptr) {
		ntx = cur->next;
		cur->next = pre;
		pre = cur;
		cur = ntx;
	}
	return pre;
}


int main(int argc, char *argv[]) {
	List l{1,2,3,4,5,6};		
	auto head = reverse(l.getHead());
	ListPrint(head);

	head = reverse_(head);
	ListPrint(head);
	return 0;
}
