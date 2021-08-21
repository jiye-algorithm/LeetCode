#include <algorithm>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
	
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		
		if (head == nullptr) return head;

		for (RandomListNode *cur = head; cur != nullptr;)
		{
			RandomListNode *node = new RandomListNode(cur->label);
			node->next = cur->next;
			cur->next = node;
			cur = cur->next->next;
		}

		for (RandomListNode* cur = head; cur;)
		{
			if (cur->random)
				cur->next->random = cur->random->next;
			cur = cur->next->next;
		}

		RandomListNode new_head(-1);
		for (RandomListNode *cur = head, *new_cur = &new_head; cur != nullptr;)
		{
			new_cur->next = cur->next;
			cur->next = cur->next->next;
			cur = cur->next;
			new_cur = new_cur->next;
		}

		return new_head.next;
	}
};