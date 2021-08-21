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
	ListNode* reverseBetween(ListNode* head, int m, int n) {

		ListNode dummy(-1);
		dummy.next = head;

		ListNode *prev_m, *prev = &dummy;
		for (int i = 1; i <= n; ++i)
		{
			if (i == m) prev_m = prev;

			if (i > m && i <= n)
			{
				prev->next = head->next;
				head->next = prev_m->next;
				prev_m->next = head;
				head = prev;
			}

			prev = head;
			head = head->next;
		}

		return dummy.next;
	}
};