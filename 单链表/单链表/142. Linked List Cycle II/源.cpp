
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
	ListNode *detectCycle(ListNode *head) {
		
		map<ListNode*, int> ans;

		while (head)
		{
			if (ans[head] > 0)
				return head;

			ans[head] = 1;
			head = head->next;
		}

		return NULL;
	}
};