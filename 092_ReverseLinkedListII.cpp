#include <iostream>

struct ListNode {
	int val;
	ListNode *next = nullptr;

	ListNode(int v=0) :val(v){ }
};

ListNode* reverseList(ListNode *head, ListNode *tail) {
	ListNode dummyH(-1);
	dummyH.next = head;
	auto pre = &dummyH;
	while(head->next!=tail) {
		auto tmp = head->next;
		head->next = tmp->next;
		tmp->next = pre->next;
		pre->next = tmp;
	}
	return dummyH.next;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode dummyH(-1);
	dummyH.next = head;
	auto pre = &dummyH, cur = &dummyH;
	while(m) {
		--m;
		--n;
		pre = cur;
		cur = cur->next;
	}
	auto beg = cur;
	while(n) {
		--n;
		cur = cur->next;
	}
	auto end = cur->next;
	auto r = reverseList(beg,end);
	pre->next = r;
	return dummyH.next;
}
