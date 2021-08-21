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

		map<int, int> ans;

		ListNode dummy(-1);
		dummy.next = head;
		ListNode* prev = &dummy;
		ListNode *temp;

		while (head)
		{
			if (ans[head->val] > 0)
			{
				prev->next = head->next;
				temp = head;
				head = head->next;
				delete temp;
				continue;
			}
			
			ans[head->val] = 1;

			prev = head;
			head = head->next;
		}

		return dummy.next;
	}
};