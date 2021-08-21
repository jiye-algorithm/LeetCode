#include <algorithm>

using namespace std;

 struct ListNode {
    int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

		ListNode* head = new ListNode(0);
		ListNode* p = head;

		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				p->next = l1;
				p = p->next;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				p = p->next;
				l2 =  l2->next;
			}
		}

		while (l1)
		{
			p->next = l1;
			p = p->next;
			l1 = l1->next;
		}

		while (l2)
		{
			p->next = l2;
			p = p->next;
			l2 = l2->next;
		}


		head = head->next;

		return head;
	}
};