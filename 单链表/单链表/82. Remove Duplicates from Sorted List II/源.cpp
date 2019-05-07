#include <algorithm>
#include <map>

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
	ListNode* deleteDuplicates(ListNode* head) {

		if (head == nullptr || head->next == nullptr) return head;

		ListNode *p = head->next;
		if (p->val == head->val)
		{
			while (p && p->val == head->val)
			{
				ListNode* temp = p;
				p = p->next;
				delete temp;
			}
			delete head;
			return deleteDuplicates(p);
		}
		else
		{
			head->next = deleteDuplicates(head->next);
			return head;
		}

	}
};