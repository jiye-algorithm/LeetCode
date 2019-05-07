/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int add = 0;
		ListNode* ans = new ListNode(0);
		ListNode* head = ans;

		ListNode* node = l1;
		while (l1 != NULL)
		{
			int temp = l1->val + l2->val + add;
			add = 0;
			if (temp > 9)
			{
				add = 1;
				temp = temp - 10;
			}
			head->next = new ListNode(temp);
			head = head->next;

			l1 = l1->next;
			l2 = l2->next;

			if (l2 == NULL) break;
		}

		while (l1 != NULL)
		{
			if (add == 1) {
				l1->val += add;
				add = 0;
			}

			if (l1->val > 9)
			{
				add = 1;
				l1->val = l1->val - 10;
			}

			head->next = l1;
			l1 = l1->next;
			head = head->next;
		}

		while (l2 != NULL)
		{
			if (add == 1) {
				l2->val += add;
				add = 0;
			}

			if (l2->val  > 9)
			{
				add = 1;
				l2->val = l2->val - 10;
			}

			head->next = l2;
			l2 = l2->next;
			head = head->next;
		}

		if (add == 1) {
			head->next = new ListNode(1);
			add = 0;
		}

		ans = ans->next;
		return ans;
	}
};

int main()
{
	ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(5);

	ListNode* node = new ListNode(4);
	ListNode* head = l1;
	head->next = node;
	head = head->next;
	head->next = new ListNode(3);
	
	head = l2;
	head->next = new ListNode(6);
	head = head->next;
	head->next = new ListNode(4);

	Solution s;
	ListNode* ans = s.addTwoNumbers(l1, l2);

	while (ans != NULL)
	{
		cout << ans->val;
		ans = ans->next;
	}

	return 0;
}