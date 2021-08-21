#include <algorithm>
#include <vector>

using namespace std;

 struct ListNode {
     int val;
    ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode* sortList(ListNode* head) {

		ListNode* p = head;

		if (head == nullptr || head->next == nullptr) return head;

		vector<int> vec;
		while (p)
		{
			vec.push_back(p->val);
			p = p->next;
		}

		sort(vec.begin(), vec.end());

		p = head;
		int i = 0;
		while (p)
		{
			p->val = vec[i++];
			p = p->next;
		}

		return head;

	}
};