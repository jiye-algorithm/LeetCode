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
	ListNode* swapPairs(ListNode* head) {
		
		if (head == nullptr || head->next == nullptr) return head;

		ListNode dummy(0);
		dummy.next = head;

		for (ListNode *prev = &dummy, *cur = prev->next, *next = cur->next;
			next;
			prev = cur	, cur = cur->next, next = cur? cur->next: nullptr)
		{
			cur->next = next->next;
			next->next = cur;
			prev->next = next;
		}

		return dummy.next;
	}
};

int main()
{
	Solution s;

	ListNode node1(1);
	node1.next = new ListNode(2);

	s.swapPairs(nullptr);

	return 0;
}