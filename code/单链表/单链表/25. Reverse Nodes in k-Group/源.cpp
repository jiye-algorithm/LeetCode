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
	ListNode* reverseKGroup(ListNode* head, int k) {

		if (head == nullptr || head->next == nullptr || k < 2) return head;

		ListNode *next_group = head;
		for (int i = 0; i < k; ++i)
			if (next_group)
				next_group = next_group->next;
			else
				return head;

		ListNode* new_next_group = reverseKGroup(next_group, k);
		ListNode *prev = nullptr, *cur = head;
		while (cur != next_group)
		{
			ListNode* next = cur->next;
			cur->next = prev ? prev : new_next_group;
			prev = cur;
			cur = next;
		}

		return prev;
	}
};

int main()
{
	Solution s;

	ListNode node1(1);
	ListNode node2(2);
	ListNode node3(3);
	ListNode node4(4);

	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;

	s.reverseKGroup(&node1, 2);

	return 0;
}