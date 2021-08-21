#include <algorithm>

 using namespace std;

 struct ListNode {
	 int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
 };

 class Solution {
 public:
	 ListNode* insertionSortList(ListNode* head) {

		 if (head == nullptr || head->next == nullptr) return head;

		 ListNode* p = head, *next = head->next;
		 ListNode* cur = nullptr;

		 head->next = nullptr;
		 p = next;
		 next = p->next;
		 while (p)
		 {
			 if (p->val <= head->val)
			 {
				 p->next = head;
				 head = p;
			 }
			 else
			 {
				 cur = head;
				 while (cur->next && cur->next->val < p->val) cur = cur->next;

				 p->next = cur->next;
				 cur->next = p;
			 }
			 p = next;
			 next = p ? p->next : nullptr;
		 }

		 return head;
	 }

 };			
