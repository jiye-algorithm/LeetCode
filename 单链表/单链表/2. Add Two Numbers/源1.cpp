#include <iostream>
#include <algorithm>

using namespace std;

class ListNode
{
public:
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode head(-1); // Í·½áµã
		ListNode* prev = &head;
		int carry = 0;

		for (ListNode* p1 = l1, *p2 = l2;
			p1 != nullptr || p2 != nullptr;
			p1 = p1 == nullptr ? nullptr : p1->next,
			p2 = p2 == nullptr? nullptr: p2->next,
			prev = prev->next)
		{
			const int a1 = p1 == nullptr ? 0 : p1->val;
			const int a2 = p2 == nullptr ? 0 : p2->val;
			int num = a1 + a2 + carry;
			carry = num / 10;
			num = num % 10;

			prev->next = new ListNode(num);
		}

		if (carry > 0)
			prev->next = new ListNode(carry);

		return head.next;
	}
};

int main()
{
	Solution s;
	ListNode l1(2);
	ListNode temp(4);
	
	l1.next = &temp;
	temp.next = new ListNode(3);

	ListNode l2(5);
	ListNode temp2(6);
	temp2.next = new ListNode(4);
	l2.next = &temp2;

	s.addTwoNumbers(&l1, &l2);

	cout << endl;

	return 0;
}