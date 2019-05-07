
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

		ListNode* result = nullptr;

		int add = 0;
		while (l1 != nullptr && l2 != nullptr)
		{
			int num = l1->val + l2->val + add;
			add = num / 10;
			num = num % 10;
			ListNode temp(num);
			
			if (result == nullptr)
				result = &temp;
			else
			{
				temp.next = result->next;
				result->next = &temp;
			}
		}

		return result;

	}
};