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
	ListNode* removeNthFromEnd(ListNode* head, int n) {

		if (head == NULL || n == 0) return head;

		ListNode dummy(-1);
		dummy.next = head;

		int len = 1;
		ListNode* p = head;
		while (p->next)
		{
			len++;
			p = p->next;
		}

		n = len - n % len ;
		p = &dummy;
		for (int i = 0; i < n; ++i)
		{
			p = p->next;
		}

		ListNode* temp = p->next;
		p->next = temp->next;
		delete temp;

		return dummy.next;
	}
};
