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
	ListNode* rotateRight(ListNode* head, int k) {

		if (head == nullptr || head->next == nullptr || k == 0) return head;

		int len = 1;
		ListNode *p = head;
		while (p->next)
		{
			len++;
			p = p->next;
		}
		p->next = head;

		k = len - k % len;

		for (int i = 0; i < k; ++i)
		{
			p = p->next;
		}

		head = p->next;
		p->next = nullptr;

		return head;

	}
};