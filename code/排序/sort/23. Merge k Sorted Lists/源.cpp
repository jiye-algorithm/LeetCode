#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {

		ListNode* head = new ListNode(0);
		ListNode* p = head;

		bool flag = true; // һ��ѭ����û�в���һ��ֵ�� ��ʾ���е������Ѿ�������ϣ� ����
		while (flag)
		{
			flag = false;	
			int min = INT_MAX;
			int index = 0;
			for (int i = 0; i < lists.size(); ++i)
			{
				if (lists[i] != NULL && lists[i]->val < min)
				{
					min = lists[i]->val;
					index = i;
					flag = true;
				}
			}

			if (flag)
			{
				p->next = lists[index];
				lists[index] = lists[index]->next;
				p = p->next;
			}
		}

		head = head->next;

		return head;
	}
};

int main()
{
	vector<ListNode*> lists;
	lists.push_back(new ListNode(1));
	lists.push_back(new ListNode(0));

	Solution s;
	s.mergeKLists(lists);

	return 0;
}