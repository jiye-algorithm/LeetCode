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
	void reorderList(ListNode* head) {

		if (head == nullptr || head->next == nullptr) return ;

		ListNode *slow, *fast;
		ListNode *prev = head;

		slow = fast = head;
		while (fast && fast->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}

		prev->next = nullptr;

		slow = reverse(slow);

		ListNode* cur = head;
		while (cur->next)
		{
			ListNode* temp = cur->next;
			cur->next = slow;
			slow = slow->next;
			cur->next->next = temp;
			cur = temp;
		}

		cur->next = slow;
	}

private:
	ListNode* reverse(ListNode* head)
	{
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode *prev = head;
		for (ListNode *cur = head->next, *next = cur->next;
			cur;
			prev = cur, cur = next, next = next ? next->next : nullptr
			)
		{
			cur->next = prev;
		}

		head->next = nullptr;

		return prev;
	}

};

int main()
{
	Solution s;

	ListNode node(1);
	node.next = new ListNode(2);

	ListNode node2(3);
	node2.next = new ListNode(4);

	ListNode node3(5);

	node.next->next = &node2;
	node2.next->next = &node3;

	s.reorderList(&node);

	return 0;
}